#pragma once
#include "Sprite.h"

class Fruit: public Sprite
{
public:
	Fruit(const float& width, const float& height, const Vector2& postion);
	unsigned int FruitPoints() const;
	void SetFruitPoints(const unsigned int& points);
private:
	unsigned int PointsPerFruit= 10;
};
