#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MenuState.hpp"

class MenuState
{
public:
    enum class MenuOption
    {
        Play,
        Options,
        Exit
    };

    void handleEvent(sf::Event& e)
    {
        if (e.type == sf::Event::KeyPressed)
        {
            switch (e.key.code)
            {
            case sf::Keyboard::Up:
                if (selectedOption > MenuOption::Play)
                    selectedOption--;
                break;

            case sf::Keyboard::Down:
                if (selectedOption < MenuOption::Exit)
                    selectedOption++;
                break;

            case sf::Keyboard::Return:
                switch (selectedOption)
                {
                case MenuOption::Play:
                    setNextState(PlayState::get());
                    break;

                case MenuOption::Options:
                    setNextState(OptionsState::get());
                    break;

                case MenuOption::Exit:
                    window.close();
                    break;
                }
                break;
            }
        }
    }


    void setNextState(std::unique_ptr<State> state)
    {
        nextState = std::move(state);
    }

    void exit()
    {
        if (nextState)
        {
            window.close();
            nextState->run(window);
        }
    }

    void MenuState::run(sf::RenderWindow& window)
    {
        this->window = window;
        sf::Font font;

        if (!font.loadFromFile("arial.ttf"))
        {

        }

        sf::Text playText;
        playText.setFont(font);
        playText.setString("Play");
        playText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 - 50);

        sf::Text optionsText;
        optionsText.setFont(font);
        optionsText.setString("Options");
        optionsText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2);


        sf::Text exitText;
        exitText.setFont(font);
        exitText.setString("Exit");
        exitText.setPosition(window.getSize().x / 2 - 50, window.getSize().y / 2 + 50);

        sf::Event e;

        while (window.isOpen())
        {
            while (window.pollEvent(e))
            {
                handleEvent(e);
            }

            window.clear();
            window.draw(playText);
            window.draw(optionsText);
            window.draw(exitText);
            window.display();

        }
    }



private:
    sf::RenderWindow& window;
    MenuOption selectedOption = MenuOption::Play;
};
