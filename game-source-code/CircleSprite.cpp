#include "CircleSprite.h"

CircleSprite::CircleSprite()
{
}

CircleSprite::CircleSprite(const float& radius, const Vector2& position): Radius(radius)
{
	PositionCenter = std::make_shared<Vector2>(position.X, position.Y);
}

Vector2 CircleSprite::GetPosition() const {
	return *PositionCenter;
}

std::shared_ptr<Vector2> CircleSprite::GetPosition_ptr() const {
	return PositionCenter;
}

float CircleSprite::GetRadius() const
{
	return Radius;
}

void CircleSprite::SetRadius(const float& radius)
{
	Radius = radius;
}
void CircleSprite::SetPosition(const Vector2& position)
{
	PositionCenter = std::make_shared<Vector2>(position.X, position.Y);
}
