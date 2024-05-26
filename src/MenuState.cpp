#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MenuState.hpp"
#include "PlayState.hpp"

MenuState::MenuState() = default;

void MenuState::update() {}

void MenuState::handleEvent( const sf::Event& e )
{
    //if (e.type == sf::Event::KeyPressed)
    //{
    //    switch (e.key.code)
    //    {
    //    case sf::Keyboard::Up:
    //        if (selectedOption == MenuOption::Options || selectedOption == MenuOption::Exit)
    //            selectedOption = MenuOption::Play;
    //        break;

    //    case sf::Keyboard::Down:
    //        if (selectedOption == MenuOption::Play)
    //            selectedOption = MenuOption::Options;
    //        else if (selectedOption == MenuOption::Options)
    //            selectedOption = MenuOption::Exit;
    //        break;

    //    case sf::Keyboard::Return:
    //        switch (selectedOption)
    //        {
    //        case MenuOption::Play:
    //            setNextState(PlayState::get());
    //            break;

    //        case MenuOption::Options:
    //            setNextState(OptionsState::get());
    //            break;

    //        case MenuOption::Exit:
    //            exit();
    //            break;
    //        }
    //        break;
    //    }
    //}
}

void MenuState::setNextState(std::unique_ptr<State> state)
{
    //nextState = std::move(state);
}

void MenuState::exit()
{
    //if (nextState)
    //{
    //    window.close();
    //    nextState->run(window);
    //}
}

void MenuState::run(sf::RenderWindow& window)
{
    //this->window = window;
    //sf::Font font;

    //if (!font.loadFromFile("arial.ttf"))
    //{
    //    // Handle error
    //}

    //sf::Text playText;
    //playText.setFont(font);
    //playText.setString("Play");
    //playText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 - 50);

    //sf::Text optionsText;
    //optionsText.setFont(font);
    //optionsText.setString("Options");
    //optionsText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2);

    //sf::Text exitText;
    //exitText.setFont(font);
    //exitText.setString("Exit");
    //exitText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 + 50);

    //sf::Event e;

    //while (window.isOpen())
    //{
    //    while (window.pollEvent(e))
    //    {
    //        handleEvent(e);
    //    }

    //    window.clear();
    //    window.draw(playText);
    //    window.draw(optionsText);
    //    window.draw(exitText);
    //    window.display();

    //    if (nextState) {
    //        window.close();
    //        nextState->run(window);
    //        break;
    //    }
    //}
}