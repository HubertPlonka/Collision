#pragma once

#include "shape.h"
#include <SFML/Graphics.hpp>

class Rectangle : public Shape {
private:
	sf::RectangleShape rectangle;

public:
	Rectangle(int x, int y, float width, float height, sf::Color color);
	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getBounds() const override;
	ShapeType getType() const override;
	sf::Vector2f getPosition() const { return rectangle.getPosition(); }
	sf::Vector2f getSize() const { return rectangle.getSize(); }
};