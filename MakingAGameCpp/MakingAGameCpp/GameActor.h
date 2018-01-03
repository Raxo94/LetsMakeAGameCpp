#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace::std;

class GameActor
{

private:
	sf::Sprite sprite;
	sf::Texture texture;


public:
	GameActor(string imageName);
	~GameActor();

	sf::Sprite& GetSprite() { return sprite; };
};

