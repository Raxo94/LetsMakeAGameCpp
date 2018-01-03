#include "Game.h"

GameHandler::GameHandler()
{
	//create window Essential
	window.create(sf::VideoMode(width, height), windowName);

	//create some actors. 

	//GameActor* temp = new GameActor("mario.png");
	//actors.push_back(temp);
	player = new PlayerActor("Klonoa.png");
	actors.push_back(player);

}

GameHandler::~GameHandler()
{
	for (GameActor* actor : actors)
	{
		delete actor;
	}
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
	window.draw(actors[0]->GetSprite());
	window.display();
}

void GameHandler::HandleEventRunning(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Right)
		{
			player->GetSprite().move(20, 0);
		}

		if (event.key.code == sf::Keyboard::Left)
		{
			player->GetSprite().move(-20, 0);
		}
	}
}
void GameHandler::HandleEventPaused(sf::Event event)
{

}
