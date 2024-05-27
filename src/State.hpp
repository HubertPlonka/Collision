#pragma once
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

class State
{
public:
	virtual ~State()								= default;
	virtual void update()							= 0;
	virtual void render( sf::RenderWindow& window ) = 0;
	virtual void handleEvent( const sf::Event& e )	= 0;
};