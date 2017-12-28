#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

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
	sf::CircleShape playerCharacter;

public:
	//Constructor
	GameHandler();
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