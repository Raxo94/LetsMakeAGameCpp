#pragma once
#include "GameActor.h"
class GameActorAlive :
	public GameActor
{	
private:
	sf::Vector2f lastPosition;
public:
	GameActorAlive();
	GameActorAlive(string imagePath, vector<TextureHolder*>* textures);
	virtual ~GameActorAlive();

	virtual void Update(double deltaTime);
	void applyGravity(double deltaTime);
	sf::Vector2f GetLastPosition() { return lastPosition; };
	void SetLastPosition() { lastPosition = GetSprite().getPosition(); };
};

