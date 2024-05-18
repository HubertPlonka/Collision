#pragma once

#include <SFML/Window.hpp>

class GameState 
	{
	public:
		virtual bool enter() = 0;
		virtual bool exit() = 0;
		virtual void handleEvent(const sf::Event& e) = 0;
		virtual void update() = 0;
		virtual void render() = 0;

		void setNextState(GameState* nextState);
		void changeState();

		virtual ~GameState() {};

	};