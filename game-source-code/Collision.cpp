#include "Collision.h"
#include <iostream>
#include <cmath>

using std::pow;

bool Collision::CheckCollision(const Sprite& firstSprite, const std::vector<Sprite>& secondSprites)
{
	for (auto secSprite : secondSprites)
	{
		if (CheckCollision(firstSprite, secSprite)) return true;
	}
	return false;
}


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
			std::cout << "collision detected" << std::endl;
			return true;
		}
		else 
		return false;
}

 bool Collision::CheckCollision(const CircleSprite& firstCircle, const CircleSprite& secondCircle)
 {
	 auto r1 = firstCircle.GetRadius();
	 auto r2 = secondCircle.GetRadius();
	 auto position1 = firstCircle.GetCenter();
	 auto posititon2 = secondCircle.GetCenter();
	 if(pow(2,(r1+r2))>(pow(2,(posititon2.X-position1.X))+pow(2,(posititon2.Y-position1.Y))))
		 return true;
	 else
		 return false;
 }
 bool Collision::CheckCollision(const CircleSprite& firstCircle, const std::vector<CircleSprite>& circles)
 {
	 for (auto circle: circles)
	 {
		 if(CheckCollision(firstCircle, circle)) return true;
	 }
	 return false;

 }

 bool Collision::CheckCollision(const CircleSprite& circle, const Sprite& rect)
 {
		 auto circleDistance_x = abs(circle.GetCenter().X - rect.GetCenter().X);
		 auto circleDistance_y = abs(circle.GetCenter().Y - rect.GetCenter().Y);

		 auto [width, height] = rect.getDimentions();

		 if (circleDistance_x > (width / 2 + circle.GetRadius())) { return false; }
		 if (circleDistance_y > (height / 2 + circle.GetRadius())) { return false; }

		 if (circleDistance_x <= (width / 2)) { return true; }
		 if (circleDistance_y <= (height / 2)) { return true; }

		 auto cornerDistance_sq = pow(2,(circleDistance_x - width/ 2)) +
			 pow(2,(circleDistance_y - height / 2));

		 return (cornerDistance_sq <= pow(2, circle.GetRadius()));
 }
 

