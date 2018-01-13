#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

using namespace::std;

struct TextureHolder {
	sf::Texture* texture;
	string Name;
};

class GameActor
{

private:
	sf::Sprite sprite;
	

public:
	GameActor();
	GameActor(string imagePath, vector<TextureHolder*>* textures);
	GameActor(string imagePath, vector<TextureHolder*>* textures, float posX, float posY);
	virtual ~GameActor();

	sf::Sprite& GetSprite() { return sprite; };
};

