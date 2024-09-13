#include "processinput.h"

sf::Vector2f velocity;
sf::Vector2f circleVelocity;

ProcessInput::ProcessInput(float radius, const sf::Vector2f& position) : Circle(radius, position)
{
}

float ProcessInput::left() const
{
    return getPosition().x - getRadius();
}

float ProcessInput::right() const
{
    return getPosition().x + getRadius();
}

float ProcessInput::up() const
{
    return getPosition().y - getRadius();
}

float ProcessInput::down() const
{
    return getPosition().y + getRadius();
}

void ProcessInput::updateMovement()
{
    circleVelocity.x = 0.0f;
    circleVelocity.y = 0.0f;

    if (right() < (800 - getRadius()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        circleVelocity.x = 0.5f; 
    }

    if (left() > (0 - getRadius()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        circleVelocity.x = -0.5f; 
    }

    if (up() > (0 - getRadius()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
        circleVelocity.y = -0.5f; 
    }

    if (down() < (600 - getRadius()) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
        circleVelocity.y = 0.5f; 
    }

    sf::Vector2f position = getShape().getPosition();
    position.x += circleVelocity.x;
    position.y += circleVelocity.y;

    getShape().setPosition(position);
}