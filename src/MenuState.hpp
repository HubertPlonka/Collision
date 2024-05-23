#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

enum class MenuOption
{
    Play,
    Options,
    Exit
};

class MenuState
{
public:
    MenuState(sf::RenderWindow& window);

    void handleEvent(const sf::Event& e);
    void setNextState(std::unique_ptr<class State> state);
    void exit();
    void run(sf::RenderWindow& window);

private:
    sf::RenderWindow& window;
    MenuOption selectedOption = MenuOption::Play;
};
