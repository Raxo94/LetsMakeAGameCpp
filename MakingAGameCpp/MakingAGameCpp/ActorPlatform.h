#pragma once
#include "GameActorAlive.h"
class ActorPlatform : public GameActor
{
public:
	ActorPlatform(string imagePath, vector<TextureHolder*>* textures);
	ActorPlatform(string imagePath, vector<TextureHolder*>* textures, float posX, float posY);
	~ActorPlatform();

	bool IsCollision(GameActorAlive* other);
};

