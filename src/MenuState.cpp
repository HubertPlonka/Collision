#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "MenuState.hpp"
#include "PlayState.hpp"

MenuState::MenuState( GameDto& gameDto ) : m_gameDto( gameDto ) {}

void MenuState::update() {}

void MenuState::render( sf::RenderWindow& window )
{
	sf::Font font;

	if( !font.loadFromFile( "../assets/arial.ttf" ) )
	{
		return;
	}

	sf::Text playText;
	playText.setFont( font );
	playText.setString( "Play" );
	playText.setPosition( window.getSize().x / 2 - 50, window.getSize().y / 2 - 50 );

	sf::Text optionsText;
	optionsText.setFont( font );
	optionsText.setString( "Options" );
	optionsText.setPosition( window.getSize().x / 2 - 50, window.getSize().y / 2 );

	sf::Text exitText;
	exitText.setFont( font );
	exitText.setString( "Exit" );
	exitText.setPosition( window.getSize().x / 2 - 50, window.getSize().y / 2 + 50 );

	window.draw( playText );
	window.draw( optionsText );
	window.draw( exitText );
}

void MenuState::handleEvent( const sf::Event& event )
{
	if( event.type == sf::Event::KeyPressed )
	{
		switch( event.key.code )
		{
		case sf::Keyboard::Up:
			if( selectedOption == MenuOption::Options || selectedOption == MenuOption::Exit )
				selectedOption = MenuOption::Play;
			break;

		case sf::Keyboard::Down:
			if( selectedOption == MenuOption::Play )
				selectedOption = MenuOption::Options;
			else if( selectedOption == MenuOption::Options )
				selectedOption = MenuOption::Exit;
			break;

		case sf::Keyboard::Return:
			switch( selectedOption )
			{
			case MenuOption::Play:
				// m_gameDto = StateId::Level;
				break;

			case MenuOption::Options:
				// m_gameDto = StateId::Options;
				break;

			case MenuOption::Exit:
				exit();
				break;
			}
			break;
		}
	}
}

void MenuState::exit()
{
	m_gameDto.isInProgress = false;
}
