#include "GameActor.h"



GameActor::GameActor(string imageName)
{
	

	if (!texture.loadFromFile("sprites/" + imageName))
	{
		std::cout << "error";
	}

	sprite.setTexture(texture);
}


GameActor::~GameActor()
{
}
