#pragma once
#ifndef sprite_h
#define sprite_h
#include "Vector2.h"
#include <tuple>
#include "string"

//square shape sprite
//i'll rename it later
class Sprite
{
public:
	Sprite() {}
	Sprite(const float& width, const float& height, const Vector2& postion);
	Vector2 GetPostion() const;
	Vector2 GetCenter() const;
	//return {Heigh, Width}
	std::tuple<float, float> getDimentions() const;
	void SetDimensions(const float& width, const float& height);
	void SetPosition(const Vector2& position);

	const std::string& Name() const { return name; }
	void Name(const std::string& name_) { name = name_; }

private:
	std::string name ="";
	float Width;
	float Height;
	//relative to the upleft-conner
	Vector2 position;
	Vector2 Center;
};

#endif

