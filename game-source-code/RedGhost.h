#pragma once
#include "Ghost.h"

//during chase mode, this ghost target is the exact position of pacman
class RedGhost: protected GhostAbstract
{
public:
	RedGhost(
		std::vector<Sprite> turningTiles,
		std::vector<Sprite> walls,
		const float& width,
		const float& height,
		const Vector2& initPosition);

	virtual void SetPackManPosition(std::shared_ptr<Vector2>& position) override;
	/*virtual std::shared_ptr<Vector2> Movement() override
	{

	};*/

};

