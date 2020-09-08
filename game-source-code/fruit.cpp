#include "fruit.h"

Fruit::Fruit(const float& radius, const Vector2& position) : CircleSprite(radius, position) {}

unsigned int Fruit::FruitPoints() const { return PointsPerFruit; }

void Fruit::SetFruitPoints(const unsigned int& points) { PointsPerFruit = points; }