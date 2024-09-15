#include "collision.h"
#include "circle.h"
#include "wheel.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>
#include <string>
#include <type_traits>

namespace Collision {
    bool collide(const Circle& circle, const Shape& shape) {
        bool result = shape.collide(circle);
        if (result) {
            if (typeid(shape) == typeid(Wheel)) {
                std::string collisionType = "Circle-Wheel";
                std::cout << "Collision detected: " << collisionType << std::endl;
            }
            else if (typeid(shape) == typeid(Rectangle)) {
                std::string collisionType = "Circle-Rectangle";
                std::cout << "Collision detected: " << collisionType << std::endl;
            }
            else if (typeid(shape) == typeid(Triangle)) {
                std::string collisionType = "Circle-Triangle";
                std::cout << "Collision detected: " << collisionType << std::endl;
            }
        }
        return result;
    }


    bool collideWheel(const Circle& circle, const Wheel& wheel) {
        sf::Vector2f axes[4] = {
            sf::Vector2f(-1, 0), // left
            sf::Vector2f(1, 0),  // right
            sf::Vector2f(0, -1), // upper
            sf::Vector2f(0, 1)   // lower
        };

        for (const auto& axis : axes) {
            sf::Vector2f circleProjection = projectCircleOntoAxis(circle, axis);
            sf::Vector2f wheelProjection = projectWheelOntoAxis(wheel, axis);

            if (!overlap(circleProjection, wheelProjection)) {
                return false;
            }
        }

        return true;
    }

    bool collideRectangle(const Circle& circle, const Rectangle& rectangle) {
        sf::Vector2f axes[2] = {
            sf::Vector2f(rectangle.getBounds().width, 0),
            sf::Vector2f(0, rectangle.getBounds().height)
        };

        for (const auto& axis : axes) {
            sf::Vector2f circleProjection = projectCircleOntoAxis(circle, axis);
            sf::Vector2f rectangleProjection = projectRectangleOntoAxis(rectangle, axis);

            if (!overlap(circleProjection, rectangleProjection)) {
                return false;
            }
        }

        return true;
    }

    bool collideTriangle(const Circle& circle, const Triangle& triangle) {
        sf::Vector2f axes[3] = {
            sf::Vector2f(triangle.getTriangle().getPoint(1) - triangle.getTriangle().getPoint(0)),
            sf::Vector2f(triangle.getTriangle().getPoint(2) - triangle.getTriangle().getPoint(1)),
            sf::Vector2f(triangle.getTriangle().getPoint(0) - triangle.getTriangle().getPoint(2))
        };

        for (const auto& axis : axes) {
            sf::Vector2f circleProjection = projectCircleOntoAxis(circle, axis);
            sf::Vector2f triangleProjection = projectTriangleOntoAxis(triangle, axis);

            if (!overlap(circleProjection, triangleProjection)) {
                return false;
            }
        }

        return true;
    }

    sf::Vector2f projectCircleOntoAxis(const Circle& circle, const sf::Vector2f& axis) {
        sf::Vector2f center = circle.getPosition();
        float radius = circle.getRadius();
        float projection = center.x * axis.x + center.y * axis.y;
        return sf::Vector2f(projection - radius, projection + radius);
    }

    sf::Vector2f projectWheelOntoAxis(const Wheel& wheel, const sf::Vector2f& axis) {
        sf::Vector2f center = wheel.getPosition();
        float radius = wheel.getRadius();
        float projection = center.x * axis.x + center.y * axis.y;
        return sf::Vector2f(projection - radius, projection + radius);
    }

    sf::Vector2f projectRectangleOntoAxis(const Rectangle& rectangle, const sf::Vector2f& axis) {
        sf::Vector2f halfSize = rectangle.getBounds().getSize() / 2.f;
        sf::Vector2f center = rectangle.getBounds().getPosition() + halfSize;

        float projection = (center.x * axis.x + center.y * axis.y);
        float minProjection = projection - halfSize.x * std::abs(axis.x) - halfSize.y * std::abs(axis.y);
        float maxProjection = projection + halfSize.x * std::abs(axis.x) + halfSize.y * std::abs(axis.y);

        return sf::Vector2f(minProjection, maxProjection);
    }

    sf::Vector2f projectTriangleOntoAxis(const Triangle& triangle, const sf::Vector2f& axis) {
        sf::Vector2f minProjection = triangle.getTriangle().getPoint(0);
        sf::Vector2f maxProjection = triangle.getTriangle().getPoint(0);

        for (int i = 0; i < 3; i++) {
            sf::Vector2f vertex = triangle.getTriangle().getPoint(i);
            float projection = vertex.x * axis.x + vertex.y * axis.y;

            if (projection < minProjection.x) {
                minProjection.x = projection;
            }
            if (projection > maxProjection.x) {
                maxProjection.x = projection;
            }
        }

        return sf::Vector2f(minProjection.x, maxProjection.x);
    }

    bool overlap(const sf::Vector2f& proj1, const sf::Vector2f& proj2) {
        return !(proj1.y < proj2.x || proj2.y < proj1.x);
    }
} 