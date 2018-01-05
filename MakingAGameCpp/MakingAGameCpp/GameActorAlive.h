#pragma once
#include "GameActor.h"
class GameActorAlive :
	public GameActor
{	
public:
	GameActorAlive(string imagePath);
	virtual ~GameActorAlive();

	virtual void Update(double deltaTime);
	void applyGravity(double deltaTime);
};

