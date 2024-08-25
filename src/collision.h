/*#pragma once

class Circle;
class Shape;

class Collision {
public:
    static bool collide(const Circle& circle, const Shape& shape);
};*/

#pragma once

#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "wheel.h"
#include "vector2f.h"
/*
class Collision {
public:
    bool collideWheel(const Circle& circle, const Wheel& wheel);
    bool collideTriangle(const Circle& circle, const Triangle& triangle);
    bool collideRectangle(const Circle& circle, const Rectangle& rectangle);
    bool collide(const Circle& circle, const Wheel& wheel);
    bool collide(const Circle& circle, const Triangle& triangle);
    bool collide(const Circle& circle, const Rectangle& rectangle);
};
*/
namespace Collision {
    bool collide(const Circle& circle, const Shape& shape);
    bool collideWheel(const Circle& circle, const Wheel& wheel);
    bool collideTriangle(const Circle& circle, const Triangle& triangle);
    bool collideRectangle(const Circle& circle, const Rectangle& rectangle);
    float distancePointLine(const sf::Vector2f& point, const sf::Vector2f& lineStart, const sf::Vector2f& lineEnd);
    float distancePointPoint(const sf::Vector2f& p1, const sf::Vector2f& p2);
    float projectCircle(const Circle& circle, const Vector2f& normal);
    float projectWheel(const Wheel& wheel, const Vector2f& normal);
    bool overlapProjections(float minA, float maxA, float minB, float maxB);
    float dotProduct(const Vector2f& a, const Vector2f& b);
}