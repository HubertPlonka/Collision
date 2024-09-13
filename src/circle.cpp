#include "circle.h"

Circle::Circle(float radius, const sf::Vector2f& position)
{
    getShape().setRadius(radius);
    getShape().setPosition(position);
}

float Circle::getRadius() const
{
    return getShape().getRadius();
}

sf::Vector2f Circle::getPosition() const
{
    return getShape().getPosition();
}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(getShape(), states);
}