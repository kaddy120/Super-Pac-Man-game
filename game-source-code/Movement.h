#pragma once
#include "Vector2.h"
#include <memory>

enum Direction { Up = 1, Down, Right, Left };

class Movement
{
public:
	Movement(const float& speed = 1.8f);
	void SetSpeed(const float& speed);
	Vector2 Move(std::shared_ptr<Vector2> Position, const Direction& direction);

private:
	float Speed;
};
