#pragma once
#include "State.hpp"
#include "GameDto.hpp"

class MenuState : public State
{
public:
	MenuState( GameDto& gameDto );

	void update() override;
	void render( sf::RenderWindow& window ) override;
	void handleEvent( const sf::Event& event ) override;

	void exit();

private:
	enum class MenuOption
	{
		Play,
		Options,
		Exit
	};

	MenuOption selectedOption = MenuOption::Play;
	GameDto& m_gameDto;
};
