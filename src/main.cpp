#include <SFML/Graphics.hpp>
#include "circle.h"
#include "collision.h"
#include "wheel.h"
#include "rectangle.h"
#include "shapeManager.h"
#include "triangle.h"
#include "processInput.h"

int main()
{
	sf::RenderWindow window( sf::VideoMode( 800, 600 ), "Collision!!!!!!!!!!!!!!" );
	ProcessInput circle(20, sf::Vector2f(400, 300));

	circle.getShape().setPosition( 400, 300 );
	circle.getShape().setRadius( 30 );
	circle.getShape().setFillColor( sf::Color::Red );
	ShapeManager shapeManager;

	std::shared_ptr<Shape> wheel = std::make_shared<Wheel>(300, 150, 50, sf::Color::Green);
	shapeManager.addShape(wheel);

	std::shared_ptr<Shape> rectangle = std::make_shared<Rectangle>(100, 300, 200, 50, sf::Color::Blue);
	shapeManager.addShape(rectangle);

	/*std::shared_ptr<Shape> triangle = std::make_shared<Triangle>(sf::Vector2f(490, 400), sf::Vector2f(620, 420), sf::Vector2f(500, 500), sf::Color::Magenta);
	shapeManager.addShape(triangle);*/

	sf::CircleShape collisionShape( 20 );

	collisionShape.setPosition( 500, 300 );

	collisionShape.setFillColor( sf::Color::Green );

	while( window.isOpen() )
	{
		sf::Event event;
		while( window.pollEvent( event ) )
		{
			if( event.type == sf::Event::Closed )
				window.close();
		}

		circle.updateMovement();
		window.clear();
		shapeManager.drawAll( window );
		window.draw( circle.getShape()); // why circle is not in shapeManager?

		// it should be encapsulated to some class ex. CollisionManager? 
		bool isColliding = false;
		for( auto& shape : shapeManager.getShapes())
		{
			if( Collision::collide( circle, *shape ) )
			{
				isColliding = true;
				break;
			}
		}
		if( isColliding )
		{
			circle.getShape().setFillColor( sf::Color::Yellow );
		}
		else
		{
			circle.getShape().setFillColor( sf::Color::Red );
		}

		window.display();
	}

	return 0;
}