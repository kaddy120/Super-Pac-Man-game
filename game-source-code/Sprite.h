#pragma once
#ifndef sprite_h
#define sprite_h
#include "Vector2.h"
#include <tuple>
#include "string"

class Sprite: protected Vector2
{
public:
	Sprite(const float& width, const float& height, const Vector2& postion);

	Vector2 GetPostion() const;
	std::tuple<float, float> getDimentions() const;
	void ChangeDimensions(const float& width, const float& height);

private:
	std::string name;
	float Width;
	float Height;
};

#endif

