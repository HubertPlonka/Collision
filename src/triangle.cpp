#include "triangle.h"

Triangle::Triangle(sf::Vector2f x, sf::Vector2f y, sf::Vector2f z, sf::Color color)
: triangle_() {
    triangle_.setPointCount(3);
    triangle_.setPoint(0, x);
    triangle_.setPoint(1, y);
    triangle_.setPoint(2, z);
    triangle_.setFillColor(color);
}

void Triangle::draw(sf::RenderWindow& window) {
    window.draw(triangle_);
}

sf::FloatRect Triangle::getBounds() const {
    return triangle_.getGlobalBounds();
}

