#include "YellowGhost.h"
#include <iostream>

YellowGhost::YellowGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : GhostAbstract(turningTiles, walls, Doors, radius, initPosition) 
{
	//PacManPreviousPosition=*PacManPostion;
}

void YellowGhost::SetPackManPosition(const std::shared_ptr<Vector2>& position)
{
	PacManPostion = position;
	PacManPreviousPosition = *position;
}

void YellowGhost::Movement()
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

void YellowGhost::SetTarget()
{
	auto Now = std::chrono::steady_clock::now();
	auto InFrontBy = 225.f;
	std::chrono::duration<float> elapsed_seconds = Now - StartTime;
	auto pos = *PacManPostion;
	if (elapsed_seconds.count() > 1.5)
	{
		std::cout << (PacManPreviousPosition.X - PacManPostion->X) << std::endl;
		if ((PacManPreviousPosition.X - PacManPostion->X)>45)
		{
			//left
			Target = pos.subtract(Vector2(InFrontBy, 45));
		}
		else if ((PacManPreviousPosition.X - PacManPostion->X)<-45)
		{
			//right
			Target = pos.add(Vector2(InFrontBy, 0));
		}
		else if ((PacManPreviousPosition.Y - PacManPostion->Y)>45)
		{
			//up
			Target = pos.subtract(Vector2(0, InFrontBy));
		}
		else if ((PacManPreviousPosition.Y - PacManPostion->Y)<-45)
		{
			//down
			Target = pos.add(Vector2(0, InFrontBy));
		}
			PacManPreviousPosition = *PacManPostion;
			StartTime = std::chrono::steady_clock::now();
	}
}

