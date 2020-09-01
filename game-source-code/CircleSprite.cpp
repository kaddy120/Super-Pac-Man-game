#include "CircleSprite.h"

CircleSprite::CircleSprite(const float& radius, const Vector2& postion): Radius(radius), Center(postion)
{}

Vector2 CircleSprite::GetCenter() const {
	return Center;
}
float CircleSprite::GetRadius() const
{
	return Radius;
}

void CircleSprite::SetRadius(const float& radius)
{
	Radius = radius;
}
void CircleSprite::SetCenter(const Vector2& position)
{
	Center = position;
}
