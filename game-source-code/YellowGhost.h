#pragma once
#include "AbstractGhost.h"

class YellowGhost: public AbstractGhost
{
public:
	YellowGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius = 20.f,
		const Vector2& initPosition = Vector2(320, 380));
	void SetPackManPosition(const std::shared_ptr<Vector2>& position) override;

private:
	void SetTarget() override;
	Vector2 PacManPreviousPosition;
	//std::shared_ptr<Vector2> PacManPostion;  //redPacManPosition
	std::chrono::steady_clock::time_point StartTime = std::chrono::steady_clock::now();
};

