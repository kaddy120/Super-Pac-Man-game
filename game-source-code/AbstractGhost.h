#pragma once
#include "CircleSprite.h"
#include "Movement.h"
#include "GhostNavigator.h"
#include <chrono>
#include "Ghost.h"

//enum class Mode { Chase, Frightened, InTheBox, Eaten, Scatter };

class AbstractGhost: public CircleSprite
{
public:
	AbstractGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& doors,
		const float& radius,
		const Vector2& initPosition);

	virtual void Move();
	void SetPackManPosition(const std::shared_ptr<Vector2>& position);
	void UpdateMode(const Mode& mode);
	void SetSpeed(const float& speed);

protected:
	int count_ = 4;
	std::chrono::steady_clock::time_point StartTime;
	Mode Mode_ = Mode::Scatter;
	std::shared_ptr<Vector2> PacManPosition;
	Vector2 DoorPosition;
	Vector2 ScatterPosition;

	Movement Movement_;
	GhostNavigator Navigator;
	void SetChaseMode();
	void ScaredMovement();
	void ChaseTargetMovement();
	virtual void SetTarget() = 0;
};

