#include "GameActorAlive.h"



GameActorAlive::GameActorAlive()
{
}

GameActorAlive::GameActorAlive(string imagePath, vector<TextureHolder*>* textures) : GameActor(imagePath, textures)
{

}


GameActorAlive::~GameActorAlive()
{
}

void GameActorAlive::Update(double deltaTime)
{

}

void GameActorAlive::applyGravity(double deltaTime)
{
	GetSprite().move(0, 150 * deltaTime);
}
