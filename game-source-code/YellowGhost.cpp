#include "YellowGhost.h"
#include <iostream>

YellowGhost::YellowGhost(
	const std::vector<CircularEntity>& turningTiles,
	const std::vector<RectangularEntity>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : AbstractGhost(turningTiles, walls, Doors, radius, initPosition) 
{
	ScatterPosition = Vector2(900.f, 0.f);
	Name("YellowGhost");
}

void YellowGhost::SetPackManPosition(const std::shared_ptr<Vector2>& position)
{
	PacManPosition = position;
	PacManPreviousPosition = *position;
}

void YellowGhost::SetTarget()
{
	auto Now = std::chrono::steady_clock::now();
	auto InFrontBy = 180.f;
	std::chrono::duration<float> elapsed_seconds = Now - StartTime;
	auto pos = *PacManPosition;
	if (elapsed_seconds.count() > 1.2 )
	{
		if ((PacManPreviousPosition.X - GetPosition().X)>45)
		{
			//left
			pos.subtract(Vector2(InFrontBy, 45));
		}
		else if ((PacManPreviousPosition.X - GetPosition().X)<-45)
		{
			//right
			pos.add(Vector2(InFrontBy, 0));
		}
		else if ((PacManPreviousPosition.Y - GetPosition().Y)>45)
		{
			//up
			pos.subtract(Vector2(0, InFrontBy));
		}
		else if ((PacManPreviousPosition.Y - GetPosition().Y)<-45)
		{
			//down
			pos.add(Vector2(0, InFrontBy));
		}
			Navigator.SetTarget(pos);
			PacManPreviousPosition = *PacManPosition;
			StartTime = std::chrono::steady_clock::now();
	}
}

