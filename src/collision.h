#pragma once

#include "circle.h"
#include "shape.h"
#include "wheel.h"
#include "rectangle.h"
#include "triangle.h"

class Wheel;
class Rectangle;
class Triangle;
class Circle;

namespace Collision {
    bool collide(const Circle& circle, const Shape& shape);
    bool collideWheel(const Circle& circle, const Wheel& wheel);
    bool collideRectangle(const Circle& circle, const Rectangle& rectangle);
    bool collideTriangle(const Circle& circle, const Triangle& triangle);

    sf::Vector2f projectCircleOntoAxis(const Circle& circle, const sf::Vector2f& axis);
    sf::Vector2f projectWheelOntoAxis(const Wheel& wheel, const sf::Vector2f& axis);
    sf::Vector2f projectRectangleOntoAxis(const Rectangle& rectangle, const sf::Vector2f& axis);
    sf::Vector2f projectTriangleOntoAxis(const Triangle& triangle, const sf::Vector2f& axis);

    bool overlap(const sf::Vector2f& proj1, const sf::Vector2f& proj2);

    bool collide(const Circle& circle, const Shape& shape);
    template<typename T1, typename T2>
    std::string getCollisionType(const T1& shape1, const T2& shape2);
}