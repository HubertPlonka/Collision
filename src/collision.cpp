#include "collision.h"
#include "circle.h"
#include <SFML/Graphics.hpp>

void Collision::collide(Circle& circle, const sf::CircleShape& shape) {
    sf::FloatRect circleBox = circle.shape.getGlobalBounds();
    sf::FloatRect shapeBox = shape.getGlobalBounds();

    if (circleBox.intersects(shapeBox)) {
        circle.shape.setFillColor(sf::Color::Yellow);
    }
    else {
        circle.shape.setFillColor(sf::Color::Red);
    }
}