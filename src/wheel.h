#pragma once

#include "shape.h"
#include <SFML/Graphics.hpp>

class Wheel : public Shape {
private:
	sf::CircleShape wheel;

public:
	Wheel(int x, int y, int radius, sf::Color color);
	void draw(sf::RenderWindow& window) override;
	sf::FloatRect getBounds() const;
};