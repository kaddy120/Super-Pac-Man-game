#include "YellowGhost.h"
#include <iostream>

YellowGhost::YellowGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : AbstractGhost(turningTiles, walls, Doors, radius, initPosition) 
{
	//PacManPreviousPosition=*PacManPostion;
	ScatterPosition = Vector2(900.f, 0.f);
	PacManPreviousPosition = GetPosition();
}

void YellowGhost::SetTarget()
{
	auto Now = std::chrono::steady_clock::now();
	auto InFrontBy = 225.f;
	std::chrono::duration<float> elapsed_seconds = Now - StartTime;
	auto pos = *GetPosition_ptr();
	if (elapsed_seconds.count() > 1.5)
	{
		std::cout << PacManPreviousPosition.X - GetPosition().X << std::endl;
		std::cout << PacManPreviousPosition.Y - GetPosition().Y << std::endl;
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
			PacManPreviousPosition = *GetPosition_ptr();
			StartTime = std::chrono::steady_clock::now();
	}
}

