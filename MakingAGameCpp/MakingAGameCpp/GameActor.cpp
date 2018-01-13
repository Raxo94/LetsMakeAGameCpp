#include "GameActor.h"



GameActor::GameActor()
{
}

GameActor::GameActor(string imagePath, vector<TextureHolder*>* textures)
{
	bool TextureExists = false;
	for (TextureHolder* textureHolder : *textures)
	{
		if (textureHolder->Name == imagePath)
		{
			sprite.setTexture(*textureHolder->texture);
			TextureExists = true;
		}
	}
	if (!TextureExists)
	{
		//create New texture.
		sf::Texture* texture = new sf::Texture;
		TextureHolder* newTextureHolder = new TextureHolder{ texture, imagePath };

		if (!texture->loadFromFile(imagePath))
		{
			std::cout << "error";
		}
		sprite.setTexture(*texture);
		textures->push_back(newTextureHolder);
	}
}
GameActor::GameActor(string imagePath, vector<TextureHolder*>* textures,  float posX, float posY)
{
	bool TextureExists = false;
	for (TextureHolder* textureHolder : *textures)
	{
		if (textureHolder->Name == imagePath)
		{
			sprite.setTexture(*textureHolder->texture);
			TextureExists = true;
		}
	}
	if (!TextureExists)
	{
		//create New texture.
		sf::Texture* texture = new sf::Texture;
		TextureHolder* newTextureHolder = new TextureHolder{ texture, imagePath };

		if (!texture->loadFromFile(imagePath))
		{
			std::cout << "error";

		}
		sprite.setTexture(*texture);
		textures->push_back(newTextureHolder);

	}
	
	sprite.setPosition(posX, posY);
}


GameActor::~GameActor()
{
}
