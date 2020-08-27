#pragma once
#include "Ghost.h"

//during chase mode, this ghost target is the exact position of pacman
class RedGhost: GhostAbstract
{
	RedGhost(
		std::vector<Sprite> turningTiles,
		std::vector<Sprite> walls,
		const float& width,
		const float& height,
		const Vector2& initPosition);

	virtual void ChaseMovement() override;

};

