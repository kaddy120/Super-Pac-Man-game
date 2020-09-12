#pragma once
#include "Ghost.h"
#include "AbstractGhost.h"


class PinkGhost: public AbstractGhost
{
public:
	PinkGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius,
		const Vector2& initPosition);

	void SetRedGhostPosition(const std::shared_ptr<Vector2>& position);

private:
	void SetTarget();
	bool RedGhostPositionIsSet = false;
	std::shared_ptr<const Vector2> RedGhostPosition;
	//this need refactoring;
	Vector2 ScatterPosition = Vector2(0.f, 0.f);

	
};

