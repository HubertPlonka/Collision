#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "CurrentState.hpp"
#include "State.hpp"

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
    void setNextState(std::unique_ptr<State> state);
    void exit();
    void run(sf::RenderWindow& window);

private:
    sf::RenderWindow& window;
    MenuOption selectedOption = MenuOption::Play;
    State* nextState;
};
