/*#include "collision.h"
#include "circle.h"
#include "shape.h"

bool Collision::collide(const Circle& circle, const Shape& shape) {
    sf::FloatRect circleBox = circle.shape.getGlobalBounds();
    sf::FloatRect shapeBox = shape.getBounds();

    return circleBox.intersects(shapeBox);
}*/

#include "collision.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "wheel.h"
#include "vector2f.h"
#include <cmath>
#include <cassert>
#include <iostream>

namespace Collision
{

    bool collide(const Circle& circle, const Shape& shape) {
        const auto& shapeType = shape.getType();
        if (shape.getType() == ShapeType::Wheel) {
            return collideWheel(circle, static_cast<const Wheel&>(shape));
        }
        else if (shape.getType() == ShapeType::Rectangle) {
            return collideRectangle(circle, static_cast<const Rectangle&>(shape));
        }
        else if (shape.getType() == ShapeType::Triangle) {
            return collideTriangle(circle, static_cast<const Triangle&>(shape));
        }
        return false;
    }

    bool collideWheel(const Circle& circle, const Wheel& wheel) {
        Vector2f wheelCenter = Vector2f(wheel.getPosition().x + wheel.getRadius() / 2.f, wheel.getPosition().y + wheel.getRadius() / 2.f);

        // Wektory normalne do krawêdzi Wheel wheel
        Vector2f normals[4] = {
            Vector2f(-1, 0),  // Lewa 
            Vector2f(1, 0),   // Prawa 
            Vector2f(0, -1),  // Górna 
            Vector2f(0, 1)    // Dolna 
        };

        float x = circle.shape.getPosition().x;
        float y = circle.shape.getPosition().y;
        Vector2f vertex(x, y);

        for (const auto& normal : normals) {
            float circleProjection = projectCircle(circle, normal);
            float wheelProjection = projectWheel(wheel, normal);

            std::cout << "Normal vector: (" << normal.x << ", " << normal.y << ")" << std::endl;
            std::cout << "Circle projection: " << circleProjection << std::endl;
            std::cout << "Wheel projection: " << wheelProjection << std::endl;

            bool overlap = circleProjection >= 0 && circleProjection <= wheelProjection;
            if (!overlap) {
                std::cout << "No overlap detected." << std::endl;
                return false;
            }
        }

        std::cout << "Collision detected!" << std::endl;
        return true;
    }

    float dotProduct(const Vector2f& a, const Vector2f& b) {
        return a.x * b.x + a.y * b.y;
    }

    Vector2f getVertex(const Wheel& wheel, int index) {
        float x = wheel.getPosition().x;
        float y = wheel.getPosition().y;
        float width = wheel.getRadius();
        float height = wheel.getRadius();

        switch (index) {
        case 0:
            return Vector2f(x, y);
        case 1:
            return Vector2f(x + width, y);
        case 2:
            return Vector2f(x + width, y + height);
        case 3:
            return Vector2f(x, y + height);
        default:
            assert(false);
            return Vector2f();
        }
    }

    float projectCircle(const Circle& circle, const Vector2f& normal) {
        Vector2f circlePosition = Vector2f(circle.shape.getPosition().x, circle.shape.getPosition().y);
        return dotProduct(circlePosition, normal) + circle.shape.getRadius();
    }

    float projectWheel(const Wheel& wheel, const Vector2f& normal) {
        float min = FLT_MAX;
        float max = FLT_MIN;

        for (int i = 0; i < 4; ++i) {
            Vector2f vertex = getVertex(wheel, i);
            Vector2f vertexRelative = vertex - Vector2f(wheel.getPosition().x, wheel.getPosition().y);
            float projection = dotProduct(vertexRelative, normal);
            projection += wheel.getRadius();
            min = std::min(min, projection);
            max = std::max(max, projection);
        }

        return max - min;
    }

    bool collideTriangle(const Circle& circle, const Triangle& triangle) {
        sf::Vector2f p1 = triangle.getTriangle().getPoint(0);
        sf::Vector2f p2 = triangle.getTriangle().getPoint(1);
        sf::Vector2f p3 = triangle.getTriangle().getPoint(2);

        float distance1 = distancePointLine(circle.shape.getPosition(), p1, p2);
        float distance2 = distancePointLine(circle.shape.getPosition(), p2, p3);
        float distance3 = distancePointLine(circle.shape.getPosition(), p3, p1);

        return distance1 < circle.shape.getRadius() || distance2 < circle.shape.getRadius() || distance3 < circle.shape.getRadius();
    }

    bool collideRectangle(const Circle& circle, const Rectangle& rectangle) {
        sf::FloatRect circleBounds = circle.shape.getGlobalBounds();
        sf::FloatRect rectangleBounds = rectangle.getBounds();

        if (circleBounds.intersects(rectangleBounds)) {
            sf::Vector2f circleCenter = circle.shape.getPosition();
            sf::Vector2f rectangleCenter(rectangleBounds.left + rectangleBounds.width / 2.0f, rectangleBounds.top + rectangleBounds.height / 2.0f);

            sf::Vector2f axis1 = sf::Vector2f(rectangleBounds.width, 0.0f);
            sf::Vector2f axis2 = sf::Vector2f(0.0f, rectangleBounds.height);
            sf::Vector2f axis3(rectangleBounds.width, rectangleBounds.height);

            float circleRadius = circle.shape.getRadius();
            float rectangleHalfWidth = rectangleBounds.width / 2.0f;
            float rectangleHalfHeight = rectangleBounds.height / 2.0f;

            float projection1 = std::abs((circleCenter.x - rectangleCenter.x) * axis1.x + (circleCenter.y - rectangleCenter.y) * axis1.y);
            float projection2 = std::abs((circleCenter.x - rectangleCenter.x) * axis2.x + (circleCenter.y - rectangleCenter.y) * axis2.y);
            float projection3 = std::abs((circleCenter.x - rectangleCenter.x) * axis3.x + (circleCenter.y - rectangleCenter.y) * axis3.y);

            if (projection1 > (circleRadius + rectangleHalfWidth) || projection2 > (circleRadius + rectangleHalfHeight) ||
                projection3 > (circleRadius + std::sqrt(rectangleHalfWidth * rectangleHalfWidth + rectangleHalfHeight * rectangleHalfHeight))) {
                return true;
            }
        }

        return false;
    }

    float distancePointLine(const sf::Vector2f& point, const sf::Vector2f& lineStart, const sf::Vector2f& lineEnd) {
        float lengthSquared = pow(lineEnd.x - lineStart.x, 2) + pow(lineEnd.y - lineStart.y, 2);
        if (lengthSquared == 0) return distancePointPoint(point, lineStart);

        float t = ((point.x - lineStart.x) * (lineEnd.x - lineStart.x) + (point.y - lineStart.y) * (lineEnd.y - lineStart.y)) / lengthSquared;
        if (t < 0) return distancePointPoint(point, lineStart);
        if (t > 1) return distancePointPoint(point, lineEnd);

        sf::Vector2f closestPoint = sf::Vector2f(lineStart.x + t * (lineEnd.x - lineStart.x), lineStart.y + t * (lineEnd.y - lineStart.y));
        return distancePointPoint(point, closestPoint);
    }

    float distancePointPoint(const sf::Vector2f& p1, const sf::Vector2f& p2) {
        return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
    }
}