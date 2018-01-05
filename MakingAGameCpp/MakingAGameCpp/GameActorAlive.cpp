#include "GameActorAlive.h"



GameActorAlive::GameActorAlive(string imagePath) : GameActor(imagePath)
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
	GetSprite().move(0, 100 * deltaTime);
}
