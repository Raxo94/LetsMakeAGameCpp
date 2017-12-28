#include<stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"





int main()
{	
	GameHandler game;

	while (game.getWindow()->isOpen())
	{
		game.Update(); //this is the main update loop that will play every frame. 
	}

	return 0;

}