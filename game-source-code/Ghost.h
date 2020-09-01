#pragma once
#include "Sprite.h"
#include "string"
#include "Collision.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <memory>
#include <chrono> 

enum Mode { Chase, Frightened, InTheBox, Captured };

enum Direction { Up, Down, Right, Left };

class GhostAbstract : public Sprite
{
public:
		//turning tiles should be a circle shaped, but for now i leave them as sprite(rectangle)
	GhostAbstract(
		std::vector<Sprite> turningTiles,
		std::vector<Sprite> walls,
		const float& width,
		const float& height,
		const Vector2& initPosition = Vector2(300,300));

	void UpdateMode(const Mode& mode);
	virtual void SetPackManPosition(std::shared_ptr<Vector2>& position);
	void SetDoorPosition(const Vector2& doorSquar);
	void SetSpeed(const float& speed);
	//virtual std::shared_ptr<Vector2> Movement() = 0;
    
protected: 
	//std::string Colour;
	float Speed = 3.f;
	Mode Mode_;
	std::chrono::steady_clock::time_point StartTime;

	std::weak_ptr<const Vector2> PacManPostion;
	Vector2 DoorPostion; 
	Vector2 Target;

	std::vector<Sprite> TurningTiles;
	std::vector<Sprite> Walls;

	Direction CurrentDirection;

	Direction RandomDirection();
	void SetChaseMode();
	//virtual void ReturnToTheBox();
	virtual void ScaredMovement();
	virtual void ChaseTarget();
	Vector2 Move(const Direction& direction);
	bool isSelectedDirectionMovable(const Direction& direction);
};

