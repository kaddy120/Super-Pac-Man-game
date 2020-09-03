#pragma once
#include "Sprite.h"
#include "string"
#include "Collision.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <memory>
#include <chrono> 

enum Mode { Chase, Frightened, InTheBox, Captured, Scatter };

enum Direction { Up =1, Down, Right, Left };

class GhostAbstract : public CircleSprite
{
public:
		//turning tiles should be a circle shaped, but for now i leave them as sprite(rectangle)
	GhostAbstract(
		std::vector<CircleSprite> turningTiles,
		std::vector<Sprite> walls,
		const float& radius,
		const Vector2& initPosition = Vector2(300,300));

	void UpdateMode(const Mode& mode);
	virtual void SetPackManPosition(const std::shared_ptr<Vector2>& position);
	void SetDoorPosition(const Vector2& doorSquar);
	void SetSpeed(const float& speed);
	virtual void Movement() = 0;
    
protected: 
	//std::string Colour;
	float Speed = 1.5f;
	int count_ = 4;
	Mode Mode_ = Mode::Scatter;
	std::chrono::steady_clock::time_point StartTime;

	std::shared_ptr<const Vector2> PacManPostion;
	Vector2 DoorPostion; 
	Vector2 Target;

	std::vector<CircleSprite> TurningTiles;
	std::vector<Sprite> Walls;

	Direction CurrentDirection = Up;

	Direction RandomDirection();
	void SetChaseMode();
	//virtual void ReturnToTheBox()
	virtual void ScaredMovement();
	virtual void ChaseTarget();
	void ChaseTargetMovement();
	Vector2 Move(const Direction& direction);
	bool isSelectedDirectionMovable(const Direction& direction);
};

