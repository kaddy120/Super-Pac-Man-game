#pragma once
#include "Sprite.h"
#include <vector>
#include "CircleSprite.h"

class Collision
{
public:
	static bool CheckCollision(const Sprite& firstSprite, const Sprite& secSprite); //square to square
	static bool CheckCollision(const Sprite& firstSprite, const std::vector<Sprite>& secondSprite); //square to squares
	static bool CheckCollision(const CircleSprite& firstCircle, const CircleSprite& secondCircle); //circle to cicle
	static bool CheckCollision(const CircleSprite& firstCircle, const std::vector<CircleSprite>& secondSprite); //circle to circles
	static bool CheckCollision(const CircleSprite& circle, const Sprite& rectangle); //circle to cicle
};

