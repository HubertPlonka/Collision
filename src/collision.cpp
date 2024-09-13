#include "collision.h"
#include "circle.h"
#include "wheel.h"
#include "rectangle.h"
#include "triangle.h"

namespace Collision {
    bool collide(const Circle& circle, const Shape& shape) {

        return shape.collide(circle);

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
        sf::Vector2f minProjection = rectangle.getBounds().getPosition();
        sf::Vector2f maxProjection = rectangle.getBounds().getPosition() + rectangle.getBounds().getSize();

        sf::Vector2f vertices[4] = {
            sf::Vector2f(minProjection.x, minProjection.y),
            sf::Vector2f(maxProjection.x, minProjection.y),
            sf::Vector2f(maxProjection.x, maxProjection.y),
            sf::Vector2f(minProjection.x, maxProjection.y)
        };

        float minProj = std::numeric_limits<float>::max();
        float maxProj = std::numeric_limits<float>::min();

        for (const auto& vertex : vertices) {
            float projection = vertex.x * axis.x + vertex.y * axis.y;
            if (projection < minProj) {
                minProj = projection;
            }
            if (projection > maxProj) {
                maxProj = projection;
            }
        }

        return sf::Vector2f(minProj, maxProj);
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