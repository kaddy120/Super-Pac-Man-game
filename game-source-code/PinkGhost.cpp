#include "PinkGhost.h"

PinkGhost::PinkGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : GhostAbstract(turningTiles, walls, Doors, radius, initPosition) {}

void PinkGhost::Movement()
{
	SetChaseMode();
	switch (Mode_)
	{
	case Mode::Chase:
		SetTarget();
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

void PinkGhost::SetTarget()
{
	CircleSprite WithinRangeCircle{ 230, GetPosition() };
	CircleSprite tempCircle{ 1, *PacManPostion };
	auto pos = GetPosition();
	if (Collision::CheckCollision(WithinRangeCircle, tempCircle))
	{
		Target = *PacManPostion;
	}
	else if (RedGhostPositionIsSet)
	{
		auto grad = (RedGhostPosition->Y -PacManPostion->Y) / (RedGhostPosition->X - PacManPostion->X);
		auto X = PacManPostion->X + (PacManPostion->X - RedGhostPosition->X)/3;
		auto C = RedGhostPosition->Y - grad * (RedGhostPosition->X);
		//straight line equation
		auto Y = grad * X + C;
		Target = Vector2(Y, X);
	}
	else
		Target = *PacManPostion;
}

void PinkGhost::SetRedGhostPosition(const std::shared_ptr<Vector2>& position)
{
	RedGhostPositionIsSet = true;
	RedGhostPosition = position;
}
