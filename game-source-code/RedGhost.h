#pragma once
#include "Ghost.h"

//during chase mode, this ghost target is the exact position of pacman
class RedGhost: public GhostAbstract
{
public:
	RedGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius,
		const Vector2& initPosition);
	
	virtual void Movement() override;

private:
	//void SetTarget();
	Vector2 ScatterPosition = Vector2(600, 900.f);
};

