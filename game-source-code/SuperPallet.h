#pragma once
#include "CircleSprite.h"
#include "IConsumable.h"

//i might inharite from Interface class colled consumables
class SuperPallet: public CircleSprite, public IConsumable
{
public:
	SuperPallet(const float& radius, const Vector2& postion, const unsigned int& points = 50);
	unsigned int GetPoints() const override;
	void SetPoints(const unsigned int& points) override;
private:
	unsigned int Points_;
};
