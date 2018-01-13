#pragma once
#include "GameActorAlive.h"
#include "PlayerActor.h"
#include "ActorPlatform.h"



class Level
{
private:
	vector<vector<GameActor*>> actorLayers;
	vector<GameActorAlive*> actorsLiving;
	vector<ActorPlatform*> platforms;
	vector<TextureHolder*>* textures;

public:
	Level(PlayerActor* player, vector<TextureHolder*>* textures);
	~Level();
	
	void LoadTextures();
	void UnloadTextures();
	vector<GameActorAlive*>& GetActorLiving() { return actorsLiving; };
	vector<vector<GameActor*>>& GetActorLayers() { return actorLayers; };
	vector<ActorPlatform*>& GetPlatforms() { return platforms; };
};

