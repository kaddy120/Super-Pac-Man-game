#include "fruit.h"

Fruit::Fruit(const float& radius, const Vector2& postion, const unsigned int& points) : CircularEntity(radius, postion)
{
	PointsPerFruit = points;
	Name("Fruit");
}

unsigned int Fruit::GetPoints() const { return PointsPerFruit; }

void Fruit::SetPoints(const unsigned int& points) { PointsPerFruit = points; }