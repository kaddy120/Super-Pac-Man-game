#include "fruit.h"

Fruit::Fruit(const float& radius, const Vector2& position, unsigned int Points) : CircleSprite(radius, position)
{
	Name("Fruit");
	PointsPerFruit = Points;
}

unsigned int Fruit::FruitPoints() const { return PointsPerFruit; }

void Fruit::SetFruitPoints(const unsigned int& points) { PointsPerFruit = points; }