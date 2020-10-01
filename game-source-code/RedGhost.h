#pragma once
#include "AbstractGhost.h"


class RedGhost: public AbstractGhost
{
public:
	RedGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius = 20.f,
		const Vector2& initPosition = Vector2(320, 380));

private:
	void SetTarget() override;
};

