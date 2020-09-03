#pragma once
#include "Ghost.h"

//during chase mode, this ghost target is the exact position of pacman
class RedGhost: public GhostAbstract
{
public:
	RedGhost(
		std::vector<CircleSprite> turningTiles,
		std::vector<Sprite> walls,
		const float& radius,
		const Vector2& initPosition);
	
	virtual void Movement() override;

private:
	//void SetTarget();
	Vector2 ScatterPosition = Vector2(900, 900.f);
};

