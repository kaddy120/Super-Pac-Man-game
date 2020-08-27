#pragma once
#include "Sprite.h"
#include <vector>

class Collision
{
public:
	static bool CheckCollision(const Sprite& firstSprite, const Sprite& secSprite);
	static bool CheckCollision(const Sprite& firstSprite, const std::vector<Sprite> secondSprites);
	//i need three collision
	//one between circle and circle - easy
	//one between circle and rectangele -- very important

};

