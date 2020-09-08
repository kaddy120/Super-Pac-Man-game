#pragma once
#include "Ghost.h"
class YellowGhost: public GhostAbstract
{
public:
	YellowGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius,
		const Vector2& initPosition);

	virtual void SetPackManPosition(const std::shared_ptr<Vector2>& position) override;

	virtual void Movement() override;
private:
	void SetTarget();
	Vector2 PacManPreviousPosition;
	std::chrono::steady_clock::time_point StartTime;
	Vector2 ScatterPosition = Vector2(900.f, 0.f);
};

