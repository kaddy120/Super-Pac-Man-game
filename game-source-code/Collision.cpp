#include "Collision.h"

bool Collision::CheckCollision(const Sprite& sprite1, const Sprite& sprite2)
{
	auto [width1,height1] = sprite1.getDimentions();
	auto [width2,height2] = sprite2.getDimentions();
	auto position1 = sprite1.GetPostion();
	auto position2 = sprite2.GetPostion();
	
		if (position1.X < position2.X + width2 &&
			position1.X + width1> position2.X &&
			position1.Y < position2.Y + height2 &&
			position1.Y + height1 > position2.Y)
		{
		if(false){
			return true;
		}
		else 
		return false;
}
