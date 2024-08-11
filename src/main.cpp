#include <SFML/Graphics.hpp>
#include "circle.h"

#include "collision.h"
#include "wheel.h"
#include "rectangle.h"
#include "shapeManager.h"
#include "triangle.h"



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Collision!!!!!!!!!!!!!!");
	Circle circle(sf::Vector2f(400, 300), 20);

	circle.shape.setPosition(400, 300);
	circle.shape.setRadius(30);
	circle.shape.setFillColor(sf::Color::Red);
	ShapeManager shapeManager;

	Wheel* wheel = new Wheel(200, 150, 50, sf::Color::Green);
	std::shared_ptr<Shape> wheelptr(wheel);
	shapeManager.addShape(wheelptr);

	Rectangle* rectangle = new Rectangle(100, 500, 200, 10, sf::Color::Blue);
	std::shared_ptr<Shape> rectangleptr(rectangle);
	shapeManager.addShape(rectangleptr);

	Triangle* triangle = new Triangle(sf::Vector2f(600, 600), sf::Vector2f(900, 700), sf::Vector2f(520, 520), sf::Color::Magenta);
	std::shared_ptr<Shape> triangleptr(triangle);
	shapeManager.addShape(triangleptr);

	sf::CircleShape collisionShape(20);

	collisionShape.setPosition(500, 300);

	collisionShape.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		circle.update();
		window.clear();
		shapeManager.drawAll(window);
		window.draw(circle.shape);

		bool isColliding = false;
		for (auto& shape : shapeManager.shapes) {
			if (Collision::collide(circle, *shape)) {
				isColliding = true;
				break;
			}
		}
		if (isColliding) {
			circle.shape.setFillColor(sf::Color::Yellow);
		}
		else {
			circle.shape.setFillColor(sf::Color::Red);
		}

		window.display();
	}

	return 0;
}