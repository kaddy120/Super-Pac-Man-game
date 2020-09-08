#pragma once
#include "CircleSprite.h"

class Fruit: public CircleSprite
{
public:
	Fruit(const float& radius, const Vector2& postion);
	unsigned int FruitPoints() const;
	void SetFruitPoints(const unsigned int& points);
private:
	unsigned int PointsPerFruit= 10;
};
