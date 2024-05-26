#pragma once
#include <SFML/Window.hpp>
#include "State.hpp"

enum class MenuOption
{
    Play,
    Options,
    Exit
};

class MenuState : public State
{
public:
    MenuState();

    void update() override;

    void handleEvent(const sf::Event& e);
    void setNextState(std::unique_ptr<State> state);
    void exit();
    void run(sf::RenderWindow& window);

private:
    /*sf::RenderWindow& window;*/
    MenuOption selectedOption = MenuOption::Play;
};
