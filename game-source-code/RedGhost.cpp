#include "RedGhost.h"
#include <iostream>

RedGhost::RedGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : GhostAbstract(turningTiles,walls, Doors, radius,initPosition) {}

void RedGhost::Movement()
{
	SetChaseMode();
	switch (Mode_)
	{
	case Mode::Chase:
		Target = *PacManPostion;
		ChaseTargetMovement();
		break;
	case Mode::Captured:
		Target = DoorPostion;
		ChaseTargetMovement();
		break;
	case Mode::Scatter:
		Target = ScatterPosition;
		ChaseTargetMovement();
		break;
	case Mode::Frightened:
		ScaredMovement();
		break;
	default:
		break;
	}
}

//void RedGhost::SetTarget()
//{
//
//}


