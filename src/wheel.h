#pragma once

#include "shape.h"
#include "collision.h"
#include <SFML/Graphics.hpp>

class Wheel : public Shape
{
private:
    sf::CircleShape wheel;

public:
    Wheel(int x, int y, int radius, sf::Color color);
    void draw(sf::RenderWindow& window) const override;
    sf::FloatRect getBounds() const override;
    ShapeType getType() const override;
    sf::Vector2f getPosition() const;
    float getRadius() const;
    bool collide(const Circle& circle) const override; 
};