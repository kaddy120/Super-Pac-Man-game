#include "CircularEntity.h"

CircularEntity::CircularEntity()
{
	PositionCenter = std::make_shared<Vector2>(0,0);
}

CircularEntity::CircularEntity(const float& radius, const Vector2& position): Radius(radius)
{
	PositionCenter = std::make_shared<Vector2>(position.X, position.Y);
}

Vector2 CircularEntity::GetPosition() const {
	return *PositionCenter;
}

std::shared_ptr<Vector2> CircularEntity::GetPosition_ptr() const {
	return PositionCenter;
}

float CircularEntity::GetRadius() const
{
	return Radius;
}

void CircularEntity::SetRadius(const float& radius)
{
	Radius = radius;
}
void CircularEntity::SetPosition(const Vector2& position)
{
	PositionCenter->X = position.X;
	PositionCenter->Y = position.Y;
}
