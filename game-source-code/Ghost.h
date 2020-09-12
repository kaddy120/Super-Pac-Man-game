#pragma once
#include "Sprite.h"
#include "string"
#include "Collision.h"
#include <vector>
#include <stdlib.h> 
#include <time.h>
#include <memory>
#include <chrono> 
#include "Door.h"
#include "Movement.h"


//enum Direction { Up =1, Down, Right, Left };
//ghost interface
class GhostAbstract : public CircleSprite
{
public:
	GhostAbstract(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius,
		const Vector2& initPosition = Vector2(300,300));

	void UpdateMode(const Mode& mode);
	virtual void SetPackManPosition(const std::shared_ptr<Vector2>& position);
	void SetDoorPosition(const Vector2& doorSquar);
	void SetSpeed(const float& speed);
	virtual void Movement() = 0;
    
protected: 

	Mode Mode_ = Mode::Scatter;
	std::shared_ptr<const Vector2> PacManPostion;
	Vector2 DoorPostion; 
	Vector2 Target;

	std::vector<CircleSprite> TurningTiles;
	std::vector<Sprite> Walls;
	std::vector<std::shared_ptr<Door>> Doors;

	void SetChaseMode();
	virtual void ScaredMovement();
	virtual void ChaseTarget();
	void ChaseTargetMovement();

private:

	float Speed = 1.5f;
	int count_ = 4;
	Direction CurrentDirection = Direction::Up;
	std::chrono::steady_clock::time_point StartTime;
	Direction RandomDirection();
	bool isSelectedDirectionMovable(const Direction& direction);
	Vector2 Move(const Direction& direction);
	bool CheckCollisionWithaDoor(const Sprite& rectangle) const;
};

