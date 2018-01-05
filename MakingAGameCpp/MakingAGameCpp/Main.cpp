#include<stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#include <stdlib.h>




int main()
{	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	sf::Clock clock;
	
	GameHandler game;
	while (game.getWindow()->isOpen())
	{
		double deltaTime = clock.restart().asSeconds();
		game.Update(deltaTime); //this is the main update loop that will play every frame. 
	}
	return 0;

}