#include <SFML/Graphics.hpp>
#include <memory>
#include "Game.hpp"

int main()
{
	sf::RenderWindow window( sf::VideoMode( 800, 600 ), "PCMan" );
	Game game{};
	game.init();

	while( window.isOpen() )
	{
		window.clear();

		sf::Event event;
		while( window.pollEvent( event ) )
		{
			game.handleEvent( event );
		}

		game.update();
		game.render( window );

		window.display();

		if (!game.isInProgress())
		{
			window.close();
		}
	}

	return 0;
}
