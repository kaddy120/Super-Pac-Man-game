#pragma once
#include "string"
#include "Vector2.h"
#include <memory>

class CircleSprite
{
	//Sprite() {}
public:
	CircleSprite(const float& radius, const Vector2& postion);
	Vector2 GetPosition() const;
	std::shared_ptr<Vector2> GetPosition_ptr() const;
	float GetRadius() const;

	void SetRadius(const float& radius);
	void SetPosition(const Vector2& position);

	const std::string& Name() const { return name; }

	void Name(const std::string& name_) { name = name_; }

private:
	std::string name = "";
	float Radius;
	std::shared_ptr<Vector2> PositionCenter;
};

