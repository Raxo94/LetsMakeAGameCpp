#include "ActorPlatform.h"



ActorPlatform::ActorPlatform(string imagePath, vector<TextureHolder*>* textures, float posX, float posY) : GameActor(imagePath, textures, posX, posY)
{

}


ActorPlatform::ActorPlatform(string imagePath, vector<TextureHolder*>* textures) : GameActor(imagePath,textures)
{
	
}

ActorPlatform::~ActorPlatform()
{
}

bool ActorPlatform::IsCollision(GameActorAlive * other) //is ska vara const funktioner.
{
	if (GetSprite().getGlobalBounds().intersects(other->GetSprite().getGlobalBounds()))
	{
	
		//platform attributes
		int platTop = GetSprite().getGlobalBounds().top;
		int platBottom = platTop + GetSprite().getLocalBounds().height;
		int platLeft = GetSprite().getGlobalBounds().left;
		int platRight = GetSprite().getGlobalBounds().left + GetSprite().getGlobalBounds().width;

		//other attributes
		int otherHeight = other->GetSprite().getLocalBounds().height;
		int otherWidth = other->GetSprite().getLocalBounds().width;
		int otherPastTop = other->GetLastPosition().y;
		int otherPastBottom = other->GetLastPosition().y + otherHeight;
		int otherPastLeft = other->GetLastPosition().x;
		int otherPastRight = otherPastLeft + otherWidth;



		if (otherPastBottom <= platTop)//Collision against top side of object
		{
			other->GetSprite().setPosition(other->GetSprite().getPosition().x, platTop - otherHeight);
		}
		else if(otherPastTop >= platBottom) //Collision against bottom side of object
		{
			other->GetSprite().setPosition(other->GetSprite().getPosition().x, platBottom);
		}


	
		else if (otherPastRight <= platLeft) //Collision against left side of object
		{
			other->GetSprite().setPosition(platLeft - otherWidth, other->GetSprite().getPosition().y) ;
		}

		else if (otherPastLeft >= platRight) //Collision against Right side of object.
		{
			other->GetSprite().setPosition(platRight, other->GetSprite().getPosition().y); // this works
		}




		return true;
	}
	else
	{
		return false;
	}
	
}
