#pragma once

#include <SFML/Graphics.hpp>

class Circle
{
private:
    sf::CircleShape shape;

public:
    Circle(float radius, const sf::Vector2f& position);

    float getRadius() const;
    sf::Vector2f getPosition() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::CircleShape& getShape() { return shape; }
    const sf::CircleShape& getShape() const { return shape; }
};

