#pragma once 

#include <SFML/Graphics.hpp>

class Circle : public sf::Drawable
{
public:
	Circle(sf::Vector2f center, float radius) {
		shape.setPosition(center);
		shape.setRadius(radius);
		shape.setFillColor(sf::Color::Blue);
		shape.setOrigin(radius, radius);
	}

	void update();
	sf::Vector2f getPosition() const;
	float getRadius() const;
	float left();
	float right();
	float up();
	float down();
	sf::CircleShape shape;
private:
	
	const float circleVelocity{ 10.f };
	sf::Vector2f velocity{ circleVelocity, circleVelocity };
	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
};