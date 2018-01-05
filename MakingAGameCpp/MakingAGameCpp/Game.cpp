#include "Game.h"

GameHandler::GameHandler()
{
	//create window Essential
	window.create(sf::VideoMode(width, height), windowName);

	//create some actors. 
	vector<GameActor*> layer1;
	vector<GameActor*> layer2;
	actorsLayers.push_back(layer1);
	actorsLayers.push_back(layer2);

	GameActor* backround = new GameActor("BGS/Sunset.jpg");
	player = new PlayerActor("Sprites/spritestrip.png");

	actorsLayers[0].push_back(backround);
	actorsLayers[1].push_back(player);
	actorsLiving.push_back(player);

}

GameHandler::~GameHandler()
{
	for (vector<GameActor*> layer : actorsLayers)
	{
		for (GameActor* actor : layer)
		{
			delete actor;
		}
	}
	
}

void GameHandler::Update(double deltaTime)
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
	for (GameActorAlive* actorAlive : actorsLiving)
	{
		actorAlive->applyGravity(deltaTime);
		actorAlive->Update(deltaTime);
	}

	//Clear Window and DrawCalls
	window.clear();

	for (vector<GameActor*> layer : actorsLayers)
	{
		for (GameActor* actor : layer)
		{
			window.draw(actor->GetSprite());
		}
	}
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
