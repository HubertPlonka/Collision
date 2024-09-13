#pragma once

#include <SFML/Graphics.hpp>

class Circle;

enum class ShapeType
{
	Wheel,
	Rectangle,
	Triangle
};

class Shape {
public:
    virtual bool collide(const Circle& circle) const = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual sf::Rect<float> getBounds() const = 0;
    virtual ShapeType getType() const = 0;
    virtual ~Shape() = default;
};