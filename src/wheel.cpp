#include "wheel.h"

Wheel::Wheel(int x, int y, int radius, sf::Color color) {
	wheel.setPosition(x, y);
	wheel.setRadius(radius);
	wheel.setFillColor(color);
}

void Wheel::draw(sf::RenderWindow& window){
	window.draw(wheel);
}

sf::FloatRect Wheel::getBounds() const {
	return wheel.getGlobalBounds();
}

ShapeType Wheel::getType() const {
	return ShapeType::Wheel;
}

sf::Vector2f Wheel::getPosition() const {
	return wheel.getPosition();
}

float Wheel::getRadius() const {
	return float(wheel.getRadius());
}
