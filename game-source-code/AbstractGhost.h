#pragma once
#include "CircleSprite.h"
#include "Movement.h"
#include "GhostNavigator.h"
#include <chrono>
#include "Definitions.h"
#include "Clock.h"

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
	virtual void SetPackManPosition(const std::shared_ptr<Vector2>& position);
	virtual void UpdateMode(const Mode& mode);
	void SetSpeed(const float& speed);
	Mode GetMode() const;

protected:
	int count_ = 4;
	std::chrono::steady_clock::time_point StartTime;
	Mode Mode_ = Mode::Scatter;
	Clock Clock_;
	Clock TClock_;
	std::shared_ptr<Vector2> PacManPosition;
	// temp
	Vector2 DoorPosition = Vector2(320, 380); //rename this, it's not doorPosition but initPosion/InsideGhostHouse.
	Vector2 ScatterPosition;

	Movement Movement_;
	GhostNavigator Navigator;
	void SetChaseMode();
	void ScaredMovement();
	void ChaseTargetMovement();
	virtual void SetTarget() = 0;
};

