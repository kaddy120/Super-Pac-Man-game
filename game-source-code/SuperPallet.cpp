#include "SuperPallet.h"

SuperPallet::SuperPallet(
	const float& radius, 
	const Vector2& postion,
	const unsigned int& points): CircleSprite(radius, postion), Points_(points)
{}

unsigned int SuperPallet::GetPoints() const {
	return Points_;
}

void SuperPallet::SetPoints(const unsigned int& points){
	Points_ = points;
}
