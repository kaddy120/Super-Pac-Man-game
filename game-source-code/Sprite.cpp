#include "Sprite.h"
#include "Vector2.h"


Sprite::Sprite(const float& width, const float& height, const Vector2& position_): Width(width), Height(height)
{
	position = position_;
}

Vector2 Sprite::GetPostion() const
{
	return position;
}

void Sprite::SetDimensions(const float& width, const float& height)
{
	Width = width;
	Height = height;
}
void Sprite::SetPosition(const Vector2& position_)
{
	position = position_;
}

std::tuple<float, float> Sprite::getDimentions() const
{
	return std::tuple<float, float>{Height, Width};
}
