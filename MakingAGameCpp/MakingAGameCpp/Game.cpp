#include "Game.h"

GameHandler::GameHandler()
{
	window.create(sf::VideoMode(width, height), windowName);
	playerCharacter = sf::CircleShape(100.f);
	playerCharacter.setFillColor(sf::Color::Green);
}

void GameHandler::Update()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();


		if (gameState == GameStates::Running)
		{
			HandleEventRunning(event);
		}
		else //if game is paused
		{
			HandleEventPaused(event);
		}

	}


	window.clear();
	window.draw(playerCharacter);
	window.display();
}

void GameHandler::HandleEventRunning(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Right)
		{
			playerCharacter.move(100, 0);
		}
	}
}
void GameHandler::HandleEventPaused(sf::Event event)
{

}
