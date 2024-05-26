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

class State;

class CurrentState
{
public:
    static std::unique_ptr<State> get() { return currentState; }
    void CurrentState::setCrntSt(std::unique_ptr<State> state) { currentState = std::move(state); }
private:
    static std::unique_ptr<State> currentState;
};


class State
{
public:
    virtual ~State() {}
    virtual void update(sf::Time dt) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};


class MenuState : public State
{
public:
    MenuState(sf::RenderWindow& window);
    void handleEvent(const sf::Event& e);
    void setNextState(std::unique_ptr<State> state);
    void exit();
    void update(sf::Time dt) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::RenderWindow& window;
    MenuOption selectedOption = MenuOption::Play;
};