#pragma once
#include "AbstractGhost.h"


class RedGhost: public AbstractGhost
{
public:
	RedGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius = 15.f,
		const Vector2& initPosition = Vector2(320, 300));

private:
	void SetTarget() override;
};

