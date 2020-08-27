#pragma once
#include "Sprite.h"
#include "string"
#include "Collision.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>

enum class Mode { Chase, Scared, InTheBox, Captured };

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
	void SetPackManPosition(const Vector2& target);
	void SetDoorPosition(const Vector2& doorSquar);
	void SetSpeed(const float& speed);
	//virtual void ReturnToTheBox();

	Vector2 Move(const Direction& direction);
	virtual void ScaredMovement();
	virtual void ChaseMovement() = 0;

protected: 

	std::string Colour;
	float Speed = 3.f;
	Mode Mode_ = Mode::Chase;
	Vector2 PacManPostion;
	Vector2 DoorPostion; 
	Vector2 Target;
	std::vector<Sprite> TurningTiles;
	std::vector<Sprite> Walls;
	//Direction PreviousDirection;
	Direction CurrentDirection;
	Direction RandomDirection();
	bool isSelectedDirectionMovable(const Direction& direction);
};

