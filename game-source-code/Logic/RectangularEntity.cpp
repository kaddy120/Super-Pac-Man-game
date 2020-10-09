#include "RectangularEntity.h"
#include "Vector2.h"


RectangularEntity::RectangularEntity()
{
	position = std::make_shared<Vector2>(0, 0);
	Center = *position;
}

RectangularEntity::RectangularEntity(const float& width, const float& height, const Vector2& position_): Width(width), Height(height)
{
	position = std::make_shared<Vector2>(position_.X, position_.Y);
	Center = *position;
	Center.add(Vector2((width / 2), (height / 2)));
}

std::shared_ptr<Vector2> RectangularEntity::GetPosition_ptr() const{
	return position;
}

Vector2 RectangularEntity::GetPosition() const {
	return *position;
}
Vector2 RectangularEntity::GetCenter() {
	Center = *position;
	return Center.add(Vector2((Width / 2), (Height / 2)));
}

void RectangularEntity::SetDimensions(const float& width, const float& height){
	Width = width;
	Height = height;
}

void RectangularEntity::SetPosition(const Vector2& position_){
	position->X = position_.X;
	position->Y = position_.Y;
	Center = *position;
	Center.add(Vector2((Width / 2), (Height / 2)));
}

std::tuple<float, float> RectangularEntity::getDimentions() const{
	return std::tuple<float, float>{ Width, Height};
}
