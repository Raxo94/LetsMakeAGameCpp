#include "Game.h"

GameHandler::GameHandler()
{
	//create window Essential
	window.create(sf::VideoMode(width, height), windowName);
	window.setFramerateLimit(60);
	

	//Load Some Levels
	player = new PlayerActor("Sprites/spritestrip.png",&textures);
	currentGameLevel = new Level(player,&textures);

}

GameHandler::~GameHandler()
{
	delete currentGameLevel;
	//since the level handels the player, deleting it is unneccesary.
	for (TextureHolder* textureHolder : textures)
	{
		delete textureHolder->texture;
		delete textureHolder;
	}
	textures.clear();
	
}

void GameHandler::Update(double deltaTime)
{

	player->SetLastPosition(); //this sets the players current position to a variable.
	//EVENTS
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

	for (GameActorAlive* actorAlive : currentGameLevel->GetActorLiving())
	{
		//actorAlive->applyGravity(deltaTime);
		actorAlive->Update(deltaTime);
	}
	for (ActorPlatform* platform : currentGameLevel->GetPlatforms())
	{
		platform->IsCollision(player);
	}

	//Clear Window and DrawCalls
	window.clear();

	for (vector<GameActor*> layer : currentGameLevel->GetActorLayers())
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

		if (event.key.code == sf::Keyboard::Up)
		{
			player->GetSprite().move(0, -20);
		}

		if (event.key.code == sf::Keyboard::Down)
		{
			player->GetSprite().move(0, 20);
		}
	}
}
void GameHandler::HandleEventPaused(sf::Event event)
{

}
