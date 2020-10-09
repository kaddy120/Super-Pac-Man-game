#include "Pellet.h"

Pellet::Pellet(
	const float& radius, 
	const Vector2& postion,
	const unsigned int& points): CircularEntity(radius, postion), Points_(points)
{
	Name("Pellet");
}

unsigned int Pellet::GetPoints() const {
	return Points_;
}

void Pellet::SetPoints(const unsigned int& points){
	Points_ = points;
}
