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

