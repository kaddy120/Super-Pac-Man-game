#include "Sprite.h"
#include "Vector2.h"


Sprite::Sprite(const float& width, const float& height, const Vector2& position): Width(width), Height(height)
{
	X = position.X;
	Y = position.Y;
}

Vector2 Sprite::GetPostion() const
{
	return Vector2(X, Y);
}