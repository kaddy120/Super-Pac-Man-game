#pragma once
#include "AbstractGhost.h"


class BlueGhost: public AbstractGhost
{
public:
	BlueGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius = 25.f,
		const Vector2& initPosition = Vector2(320, 300));

private:
	void SetTarget() override;
};

