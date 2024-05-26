#pragma once
#include "State.hpp"
#include <memory>
#include "GameDto.hpp"

class Game final
{
public:
	void init();
	void update();
	void render( sf::RenderWindow& window );
	void handleEvent( const sf::Event& event );

	bool isInProgress() const;

private:
	std::unique_ptr< State > m_currentState;
	GameDto m_gameDto;
};