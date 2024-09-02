/*#pragma once

class Circle;
class Shape;

class Collision {
public:
	static bool collide(const Circle& circle, const Shape& shape);
};*/

#pragma once

#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
#include "wheel.h"

namespace Collision
{
bool collide( const Circle& circle, const MyShape& shape );
bool collideWheel( const Circle& circle, const Wheel& wheel );
bool collideTriangle( const Circle& circle, const Triangle& triangle );
bool collideRectangle( const Circle& circle, const Rectangle& rectangle );
float distancePointLine( const sf::Vector2f& point, const sf::Vector2f& lineStart, const sf::Vector2f& lineEnd );
float distancePointPoint( const sf::Vector2f& p1, const sf::Vector2f& p2 );
float projectCircle( const Circle& circle, const sf::Vector2f& normal );
float projectWheel( const Wheel& wheel, const sf::Vector2f& normal );
float dotProduct( const sf::Vector2f& a, const sf::Vector2f& b );
} // namespace Collision