#include <SFML/Graphics.hpp>
#include <memory>
#include "MenuState.hpp"
#include "PlayState.hpp"
#include "OptionsState.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "PCMan");
    std::unique_ptr<State> menuState = std::make_unique<MenuState>(window);
    CurrentState::set(std::move(menuState));
    //MenuState menuState(window);

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e)) 
        {
            /* {
                menuState.handleEvent(e);
            }*/
            if (event.type = sf::Event::Closed)
                window.close();

            CurrentState::get()->handleEvent(e);
        }

        CurrentState::get()->update(sf::seconds(1.0f / 60.0f));
        CurrentState::get()->render(window);
        /*
        window.clear();
        menuState.run(window);
        window.display();
        */
    }

    return 0;
}
