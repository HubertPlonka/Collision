#pragma once

#include <SFML/Graphics.hpp>

enum class ShapeType
{
	Wheel,
	Rectangle,
	Triangle
};

class MyShape
{
public:
	virtual void draw( sf::RenderWindow& window ) = 0;
	virtual sf::FloatRect getBounds() const		  = 0;
	virtual ShapeType getType() const			  = 0;
};