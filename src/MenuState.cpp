#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum class MenuOption

{
    Play,
    Game,
    Options,
    Exit
};


class MenuState
{
public:

    void handleEvent(sf::Event& e)
    {
        if (e.type == sf::Event::KeyPressed)
        {
            switch (e.key.code)
            {
            case sf::Keyboard::Up:
                if (selectedOption > MenuOption::Play)
                    --selectedOption;
                break;

            case sf::Keyboard::Down:
                if (selectedOption < MenuOption::Exit)
                    ++selectedOption;
                break;

            case sf::Keyboard::Return:
                switch (selectedOption)
                {
                case MenuOption::Play:
                    setNextState(PlayState::get());
                    break;

                case MenuOption::Game:
                    setNextState(GameState::get());
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

    }


private:
    sf::RenderWindow& window;
    MenuOption selectedOption = MenuOption::Play;
};
