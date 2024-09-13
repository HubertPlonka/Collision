#pragma once

#include "shape.h"
#include <SFML/Graphics.hpp>

class Triangle : public Shape
{
private:
	sf::ConvexShape triangle_;

public:
	Triangle( sf::Vector2f x, sf::Vector2f y, sf::Vector2f z, sf::Color color );
	void draw(sf::RenderWindow& window) const override;
	sf::Rect<float> getBounds() const override;
	ShapeType getType() const override;
	const sf::ConvexShape& getTriangle() const;
};