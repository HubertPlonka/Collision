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
#include <cmath>

namespace Collision {

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
        float distance = sqrt(pow(circle.shape.getPosition().x - wheel.getPosition().x, 2) +
            pow(circle.shape.getPosition().y - wheel.getPosition().y, 2));
        return distance <= (circle.shape.getRadius() + wheel.getRadius());
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
        sf::Vector2f p1 = rectangle.getPosition();
        sf::Vector2f p2 = sf::Vector2f(p1.x + rectangle.getSize().x, p1.y);
        sf::Vector2f p3 = sf::Vector2f(p1.x + rectangle.getSize().x, p1.y + rectangle.getSize().y);
        sf::Vector2f p4 = sf::Vector2f(p1.x, p1.y + rectangle.getSize().y);

        float distance1 = distancePointLine(circle.shape.getPosition(), p1, p2);
        float distance2 = distancePointLine(circle.shape.getPosition(), p2, p3);
        float distance3 = distancePointLine(circle.shape.getPosition(), p3, p4);
        float distance4 = distancePointLine(circle.shape.getPosition(), p4, p1);

        return distance1 < circle.shape.getRadius() || distance2 < circle.shape.getRadius() || distance3 < circle.shape.getRadius() || distance4 < circle.shape.getRadius();
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