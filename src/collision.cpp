#include "collision.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "wheel.h"
#include <cmath>
#include <cassert>
#include <iostream>

namespace Collision
{

bool collide( const Circle& circle, const MyShape& shape )
{
	const auto& shapeType = shape.getType();
	if( shape.getType() == ShapeType::Wheel )
	{
		return collideWheel( circle, static_cast< const Wheel& >( shape ) );
	}
	else if( shape.getType() == ShapeType::Rectangle )
	{
		return collideRectangle( circle, static_cast< const Rectangle& >( shape ) );
	}
	else if( shape.getType() == ShapeType::Triangle )
	{
		return collideTriangle( circle, static_cast< const Triangle& >( shape ) );
	}
	return false;
}

sf::Vector2f projectCircleOntoAxis( const Circle& circle, const sf::Vector2f& axis )
{
	sf::Vector2f center = circle.getPosition();
	float radius		= circle.getRadius();
	float projection	= center.x * axis.x + center.y * axis.y;
	return sf::Vector2f( projection - radius, projection + radius );
}

sf::Vector2f projectCircleOntoAxis( const Wheel& circle, const sf::Vector2f& axis )
{
	sf::Vector2f center = circle.getPosition();
	float radius		= circle.getRadius();
	float projection	= center.x * axis.x + center.y * axis.y;
	return sf::Vector2f( projection - radius, projection + radius );
}

bool overlap( const sf::Vector2f& proj1, const sf::Vector2f& proj2 )
{
	return !( proj1.y < proj2.x || proj2.y < proj1.x );
}

bool collideWheel( const Circle& circle, const Wheel& wheel )
{
	sf::Vector2f wheelCenter
		= sf::Vector2f( wheel.getPosition().x + wheel.getRadius() / 2.f, wheel.getPosition().y + wheel.getRadius() / 2.f );

	// vectors normal to edge
	static sf::Vector2f normals[ 4 ] = {
		sf::Vector2f( -1, 0 ), // left
		sf::Vector2f( 1, 0 ),  // right
		sf::Vector2f( 0, -1 ), // upper
		sf::Vector2f( 0, 1 )   // lower
	};

	float x = circle.shape.getPosition().x;
	float y = circle.shape.getPosition().y;
	sf::Vector2f vertex( x, y );

	for( const auto& normal : normals )
	{
		auto circleProjection = projectCircleOntoAxis( circle, normal );
		auto wheelProjection  = projectCircleOntoAxis( wheel, normal );

		if( overlap( circleProjection, wheelProjection ) )
		{
			std::cout << "Collision detected!" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Circles are not overlapping on the given axis." << std::endl;
			return false;
		}

	}

	return true;
}

float dotProduct( const sf::Vector2f& a, const sf::Vector2f& b )
{
	return a.x * b.x + a.y * b.y;
}

sf::Vector2f getVertex( const Wheel& wheel, int index )
{
	float x		 = wheel.getPosition().x;
	float y		 = wheel.getPosition().y;
	float width	 = wheel.getRadius();
	float height = wheel.getRadius();

	switch( index )
	{
	case 0:
		return sf::Vector2f( x, y );
	case 1:
		return sf::Vector2f( x + width, y );
	case 2:
		return sf::Vector2f( x + width, y + height );
	case 3:
		return sf::Vector2f( x, y + height );
	default:
		assert( false );
		return sf::Vector2f();
	}
}

float projectCircle( const Circle& circle, const sf::Vector2f& normal )
{
	sf::Vector2f circlePosition = sf::Vector2f( circle.shape.getPosition().x, circle.shape.getPosition().y );
	return dotProduct( circlePosition, normal ) + circle.shape.getRadius();
}

float projectWheel( const Wheel& wheel, const sf::Vector2f& normal )
{
	float min = FLT_MAX;
	float max = FLT_MIN;

	for( int i = 0; i < 4; ++i )
	{
		sf::Vector2f vertex			= getVertex( wheel, i );
		sf::Vector2f vertexRelative = vertex - sf::Vector2f( wheel.getPosition().x, wheel.getPosition().y );
		float projection		= dotProduct( vertexRelative, normal );
		projection += wheel.getRadius();
		min = std::min( min, projection );
		max = std::max( max, projection );
	}

	return max - min;
}

bool collideTriangle( const Circle& circle, const Triangle& triangle )
{
	sf::Vector2f p1 = triangle.getTriangle().getPoint( 0 );
	sf::Vector2f p2 = triangle.getTriangle().getPoint( 1 );
	sf::Vector2f p3 = triangle.getTriangle().getPoint( 2 );

	float distance1 = distancePointLine( circle.shape.getPosition(), p1, p2 );
	float distance2 = distancePointLine( circle.shape.getPosition(), p2, p3 );
	float distance3 = distancePointLine( circle.shape.getPosition(), p3, p1 );

	return distance1 < circle.shape.getRadius() || distance2 < circle.shape.getRadius()
		|| distance3 < circle.shape.getRadius();
}

bool collideRectangle( const Circle& circle, const Rectangle& rectangle )
{
	sf::FloatRect circleBounds	  = circle.shape.getGlobalBounds();
	sf::FloatRect rectangleBounds = rectangle.getBounds();

	if( circleBounds.intersects( rectangleBounds ) )
	{
		sf::Vector2f circleCenter = circle.shape.getPosition();
		sf::Vector2f rectangleCenter( rectangleBounds.left + rectangleBounds.width / 2.0f,
									  rectangleBounds.top + rectangleBounds.height / 2.0f );

		sf::Vector2f axis1 = sf::Vector2f( rectangleBounds.width, 0.0f );
		sf::Vector2f axis2 = sf::Vector2f( 0.0f, rectangleBounds.height );
		sf::Vector2f axis3( rectangleBounds.width, rectangleBounds.height );

		float circleRadius		  = circle.shape.getRadius();
		float rectangleHalfWidth  = rectangleBounds.width / 2.0f;
		float rectangleHalfHeight = rectangleBounds.height / 2.0f;

		float projection1 = std::abs( ( circleCenter.x - rectangleCenter.x ) * axis1.x
									  + ( circleCenter.y - rectangleCenter.y ) * axis1.y );
		float projection2 = std::abs( ( circleCenter.x - rectangleCenter.x ) * axis2.x
									  + ( circleCenter.y - rectangleCenter.y ) * axis2.y );
		float projection3 = std::abs( ( circleCenter.x - rectangleCenter.x ) * axis3.x
									  + ( circleCenter.y - rectangleCenter.y ) * axis3.y );

		if( projection1 > ( circleRadius + rectangleHalfWidth ) || projection2 > ( circleRadius + rectangleHalfHeight )
			|| projection3 > ( circleRadius
							   + std::sqrt( rectangleHalfWidth * rectangleHalfWidth
											+ rectangleHalfHeight * rectangleHalfHeight ) ) )
		{
			return true;
		}
	}

	return false;
}

float distancePointLine( const sf::Vector2f& point, const sf::Vector2f& lineStart, const sf::Vector2f& lineEnd )
{
	float lengthSquared = pow( lineEnd.x - lineStart.x, 2 ) + pow( lineEnd.y - lineStart.y, 2 );
	if( lengthSquared == 0 )
		return distancePointPoint( point, lineStart );

	float t = ( ( point.x - lineStart.x ) * ( lineEnd.x - lineStart.x )
				+ ( point.y - lineStart.y ) * ( lineEnd.y - lineStart.y ) )
		/ lengthSquared;
	if( t < 0 )
		return distancePointPoint( point, lineStart );
	if( t > 1 )
		return distancePointPoint( point, lineEnd );

	sf::Vector2f closestPoint
		= sf::Vector2f( lineStart.x + t * ( lineEnd.x - lineStart.x ), lineStart.y + t * ( lineEnd.y - lineStart.y ) );
	return distancePointPoint( point, closestPoint );
}

float distancePointPoint( const sf::Vector2f& p1, const sf::Vector2f& p2 )
{
	return sqrt( pow( p1.x - p2.x, 2 ) + pow( p1.y - p2.y, 2 ) );
}
} // namespace Collision