#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "GameActor.h"
#include "PlayerActor.h"
using namespace::std;

enum GameStates
{
	Paused,
	Running
};

static class GameHandler
{
private:
	sf::RenderWindow window;
	unsigned int width = 1920; 
	unsigned int height = 1080;
	GameStates gameState = GameStates::Running;
	char* windowName = "Wonder World";
	
	PlayerActor* player;
	vector<GameActor*> actors;
	
	

public:
	//Constructor
	GameHandler();
	~GameHandler();
	//Get/Setters
	sf::RenderWindow* getWindow() {return &window; }; //returns a pointer to the game window
	int getWidth() { return width; };
	void setWidth(int width) { this->width = width;};

	int getHeight() { return height; };
	void setHeight(int height) { this->height = height;};

	char* getWindowName() { return windowName; };
	GameStates getGameState() { return gameState; };
	
	//Functions
	void Update();
	void HandleEventRunning(sf::Event event);
	void HandleEventPaused(sf::Event event);

};