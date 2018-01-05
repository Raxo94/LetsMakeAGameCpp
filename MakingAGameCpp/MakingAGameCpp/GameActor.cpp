#include "GameActor.h"



GameActor::GameActor(string imagePath)
{
	
	if (!texture.loadFromFile(imagePath))
	{
		std::cout << "error";
	}

	sprite.setTexture(texture);
}


GameActor::~GameActor()
{
}
