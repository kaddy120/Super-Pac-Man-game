#include "Collision.h"
#include <iostream>
#include <cmath>

using std::pow;

bool Collision::CheckCollision(const RectangularEntity& firstRectangle, const std::vector<RectangularEntity>& secondRectangle)
{
	for (auto secRectangularEntity : secondRectangle)
	{
		if (CheckCollision(firstRectangle, secRectangularEntity)) return true;
	}
	return false;
}

    /**
    * @brief Parametrized constructor. Inherits from MovingGameObject class. Creates the alienBullet gameObject.
    * @param firstRectangle
    * @param secondRectangle

    @return bool
    */

bool Collision::CheckCollision(const RectangularEntity& firstRectangle, const RectangularEntity& RectangularEntity2)
{
	auto [width1,height1] = firstRectangle.getDimentions();
	auto [width2,height2] = RectangularEntity2.getDimentions();
	auto position1 = firstRectangle.GetPosition();
	auto position2 = RectangularEntity2.GetPosition();

		if (position1.X <= position2.X + width2 &&
			position1.X + width1 >= position2.X &&
			position1.Y <= position2.Y + height2 &&
			position1.Y + height1 >= position2.Y)
		{
			//std::cout << "collision detected" << std::endl;
			return true;
		}
		else
		return false;
}

 bool Collision::CheckCollision(const CircularEntity& firstCircle, const CircularEntity& secondCircle)
 {
	 auto r1 = firstCircle.GetRadius();
	 auto r2 = secondCircle.GetRadius();
	 auto position1 = firstCircle.GetPosition();
	 auto posititon2 = secondCircle.GetPosition();
	 if(pow((r1 + r2), 2) > (pow((posititon2.X - position1.X), 2) + pow((posititon2.Y - position1.Y), 2)))
		 return true;
	 else
		 return false;
 }
 bool Collision::CheckCollision(const CircularEntity& firstCircle, const std::vector<CircularEntity>& circles)
 {
	 for (auto circle: circles)
	 {
		 if(CheckCollision(firstCircle, circle)) return true;
	 }
	 return false;

 }

 bool Collision::CheckCollision(const CircularEntity& circle, const RectangularEntity& rect)
 {
		 auto [width, height] = rect.getDimentions();
		 /*auto circleDistance_x = abs(circle.GetPosition().X - rect.GetCenter().X);
		 auto circleDistance_y = abs(circle.GetPosition().Y - rect.GetCenter().Y);*/

		 auto circleDistance_x = abs(circle.GetPosition().X - (rect.GetPosition().X +width/2));
		 auto circleDistance_y = abs(circle.GetPosition().Y - (rect.GetPosition().Y+height/2));

		 if (circleDistance_x > (width / 2 + circle.GetRadius())) { return false; }
		 if (circleDistance_y > (height / 2 + circle.GetRadius())) { return false; }

		 if (circleDistance_x <= (width / 2)) { return true; }
		 if (circleDistance_y <= (height / 2)) { return true; }

		 auto cornerDistance_sq = pow((circleDistance_x - width/ 2),2) +
			 pow((circleDistance_y - height / 2),2);

		 return (cornerDistance_sq <= pow( circle.GetRadius(),2));

 }

 bool Collision::CheckCollision(const RectangularEntity& rectangle, const std::vector<CircularEntity>& circles)
 {
	 for (auto circle : circles)
	 {
		 if (CheckCollision(circle, rectangle)) return true;
	 }
	 return false;
 }
