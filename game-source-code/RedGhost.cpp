#include "RedGhost.h"

RedGhost::RedGhost(
	std::vector<CircleSprite> turningTiles,
	std::vector<Sprite> walls,
	const float& radius,
	const Vector2& initPosition) : GhostAbstract(turningTiles,walls,radius,initPosition) {}

void RedGhost::Movement()
{
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


