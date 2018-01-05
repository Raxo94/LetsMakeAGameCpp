#pragma once
#include "GameActorAlive.h"
class PlayerActor : public GameActorAlive
{
private:
	double clockAnimation = 0;
	double frameAnimation = 0;
public:
	PlayerActor(string imagePath);
	~PlayerActor();

	void Update(double deltaTime);
};

