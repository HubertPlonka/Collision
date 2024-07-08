#include <SFML/Graphics.hpp>
#include "circle.h"
#include "collision.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Collision!!!!!!!!!!!!!!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    Circle circle(sf::Vector2f(400, 300), 20);

    circle.shape.setPosition(400, 300);
    circle.shape.setRadius(30);
    circle.shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //sf::Mouse::setPosition(sf::Vector2i(400, 300), window);
        circle.update();
        window.clear();
        window.draw(shape);
        window.draw(circle.shape);
        Collision::collide(circle, shape);
        window.display();
    }

    return 0;
}