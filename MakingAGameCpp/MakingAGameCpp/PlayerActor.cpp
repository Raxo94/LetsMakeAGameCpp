#include "PlayerActor.h"



PlayerActor::PlayerActor(string imagePath, vector<TextureHolder*>* textures) : GameActorAlive(imagePath, textures)
{
	GetSprite().setTextureRect(sf::IntRect(0, 0, 256, 256));
}


PlayerActor::~PlayerActor()
{

}

void PlayerActor::Update(double deltaTime)
{
	clockAnimation += deltaTime;

	if (clockAnimation > 0.1)
	{
		clockAnimation = 0;
		frameAnimation++;
		if (frameAnimation > 5)
		{
			frameAnimation = 0;
		}
		
		GetSprite().setTextureRect(sf::IntRect((256 * frameAnimation), 0, 256, 256));
		
	}

	
}
