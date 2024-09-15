#include "wheel.h"

Wheel::Wheel(int x, int y, int radius, sf::Color color) {
    wheel.setPosition(x, y);
    wheel.setRadius(radius);
    wheel.setFillColor(color);
}

void Wheel::draw(sf::RenderWindow& window) const {
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

bool Wheel::collide(const Circle& circle) const {
    return Collision::collideWheel(circle, *this);
}