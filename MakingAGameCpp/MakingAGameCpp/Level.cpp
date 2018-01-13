#include "Level.h"



Level::Level(PlayerActor* player, vector<TextureHolder*>* textures)
{
	this->textures = textures;
	vector<GameActor*> layer1;
	vector<GameActor*> layer2;
	actorLayers.push_back(layer1);
	actorLayers.push_back(layer2);
	
	GameActor* backround = new GameActor("BGS/Sunset.jpg",textures);
	actorLayers[0].push_back(backround);

	ActorPlatform* platform = new ActorPlatform("Sprites/platform.png",textures,400,400);
	actorLayers[1].push_back(platform);
	platforms.push_back(platform);
	
	actorLayers[1].push_back(player); //I am still uncertain if this is the best way to handle the player character. 
	actorsLiving.push_back(player);
}


Level::~Level()
{
	for (vector<GameActor*> layer : actorLayers)
	{
		for (GameActor* actor : layer)
		{
			delete actor;
		}
	}
}

void Level::LoadTextures()
{
}

void Level::UnloadTextures()
{
}
