#pragma once

#include "circle.h"
#include <SFML/Window.hpp>

class ProcessInput : public Circle
{
public:
    ProcessInput(float radius, const sf::Vector2f& position);

    float left() const;
    float right() const;
    float up() const;
    float down() const;

    void updateMovement();
};
