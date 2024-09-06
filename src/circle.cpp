#include "circle.h"

//TODO: format code
void Circle::update()
{
    velocity.x = 0;
    velocity.y = 0;
    if (right() < 800 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) { // It could be processInput interface.
        velocity.x = circleVelocity/8;
    }
    if (left() > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        velocity.x = -circleVelocity/8;
    }
    if (up() > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        velocity.y = -circleVelocity/8;
    }
    if (down() < 600 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        velocity.y = circleVelocity/8;
    }
    shape.move(velocity);

}
float Circle::left() 
{
    return this->shape.getPosition().x - shape.getRadius();
}

float Circle::right()
{
    return this->shape.getPosition().x + shape.getRadius();
}

float Circle::up()
{
    return this->shape.getPosition().y - shape.getRadius();
}

float Circle::down()
{
    return this->shape.getPosition().y + shape.getRadius();
}

float Circle::getRadius() const
{
    return shape.getRadius();
}

sf::Vector2f Circle::getPosition() const
{
    return shape.getPosition();
}

void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}