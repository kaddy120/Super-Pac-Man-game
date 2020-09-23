#pragma once
#include "CircleSprite.h"

//i might inharite from Interface class colled consumables
class SuperPallet: public CircleSprite
{
public:
	SuperPallet(const float& radius, const Vector2& postion, const unsigned int& points = 50);
	unsigned int Points() const;
	void SetPoints(const unsigned int& points);
private:
	unsigned int Points_;
};
