#pragma once
#include "string"
#include "Vector2.h"

class CircleSprite
{
	//Sprite() {}
public:
	CircleSprite(const float& radius, const Vector2& postion);
	Vector2 GetCenter() const;
	float GetRadius() const;

	void SetRadius(const float& radius);
	void SetCenter(const Vector2& position);

	const std::string& Name() const { return name; }

	void Name(const std::string& name_) { name = name_; }

private:
	std::string name = "";
	float Radius;
	Vector2 Center;
};

