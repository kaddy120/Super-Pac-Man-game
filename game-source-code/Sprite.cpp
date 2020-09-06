#include "Sprite.h"
#include "Vector2.h"


Sprite::Sprite(const float& width, const float& height, const Vector2& position_): Width(width), Height(height)
{
	position = std::make_shared<Vector2>(position_.X, position_.Y);
	Center = *position;
	Center.add(Vector2((width / 2), (height / 2)));
}

std::shared_ptr<Vector2> Sprite::GetPosition_ptr() const{
	return position;
}

Vector2 Sprite::GetPosition() const {
	return *position;
}
Vector2 Sprite::GetCenter() const {
	return Center;
}

void Sprite::SetDimensions(const float& width, const float& height){
	Width = width;
	Height = height;
}

void Sprite::SetPosition(const Vector2& position_){
	position->X = position_.X;
	position->Y = position_.Y;
	Center = *position;
	Center.add(Vector2((Width / 2), (Height / 2)));
}

std::tuple<float, float> Sprite::getDimentions() const{
	return std::tuple<float, float>{ Width, Height};
}
