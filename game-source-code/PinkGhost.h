#pragma once
#include "Ghost.h"


class PinkGhost: protected GhostAbstract
{
	PinkGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius,
		const Vector2& initPosition);

	virtual void Movement() override;
	void SetRedGhostPosition(const std::shared_ptr<Vector2>& position);

private:
	void SetTarget();
	Vector2 ScatterPosition = Vector2(0.f, 0.f);

	
};

