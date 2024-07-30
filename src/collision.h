#pragma once

class Circle;
class Shape;

class Collision {
public:
    static bool collide(const Circle& circle, const Shape& shape);
};