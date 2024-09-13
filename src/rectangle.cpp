#include "rectangle.h"

Rectangle::Rectangle(int x, int y, float width, float height, sf::Color color) {
		rectangle.setPosition(x, y);
		rectangle.setSize(sf::Vector2f(width, height));
		rectangle.setFillColor(color);
};
void Rectangle::draw(sf::RenderWindow& window) const {
	window.draw(rectangle);
};

sf::FloatRect Rectangle::getBounds() const {
	return rectangle.getGlobalBounds();
}

ShapeType Rectangle::getType() const {
	return ShapeType::Rectangle;
}
