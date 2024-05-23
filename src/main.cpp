#include <SFML/Graphics.hpp>
#include "MenuState.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "PCMan");
    MenuState menuState(window);

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(event))
        {
            menuState.handleEvent(e);
        }

        window.clear();
        window.run(window);
        window.display();
    }

    return 0;
}
