#pragma once

#include <SFML/Graphics.hpp>
#include "circle.h"

class Collision {
public:
    static void collide(Circle& circle, const sf::CircleShape& shape);
}; 