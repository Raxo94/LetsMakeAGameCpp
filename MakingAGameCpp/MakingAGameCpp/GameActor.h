#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace::std;

class GameActor
{

private:
	sf::Sprite sprite;
	sf::Texture texture;
	

public:
	GameActor(string imagePath);
	virtual ~GameActor();

	sf::Sprite& GetSprite() { return sprite; };
};

