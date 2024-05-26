#include "Game.hpp"
#include "MenuState.hpp"

void Game::init()
{
	m_currentState = std::make_unique< MenuState >( m_gameDto );
	m_gameDto.isInProgress = true;
}

void Game::update()
{
	m_currentState->update();
}

void Game::render( sf::RenderWindow& window )
{
	m_currentState->render( window );
}

void Game::handleEvent( const sf::Event& event )
{
	m_currentState->handleEvent( event );
}

bool Game::isInProgress() const
{
	return m_gameDto.isInProgress;
}
