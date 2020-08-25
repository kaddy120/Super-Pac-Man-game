#include "fruit.h"

Fruit::Fruit(const float& width, const float& height, const Vector2& position) : Sprite(width, height, position) {}

unsigned int Fruit::FruitPoints() const { return PointsPerFruit; }

void Fruit::SetFruitPoints(const unsigned int& points) { PointsPerFruit = points; }