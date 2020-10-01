#include "PinkGhost.h"

PinkGhost::PinkGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const std::shared_ptr<Vector2>& RedGhostposition,
	const float& radius,
	const Vector2& initPosition) : AbstractGhost(turningTiles, walls, Doors, radius, initPosition)
{
	RedGhostPositionIsSet = true;
	RedGhostPosition = RedGhostposition;
	Name("PinkGhost");
}


void PinkGhost::SetTarget()
{
	CircleSprite WithinRangeCircle{ 230, GetPosition() };
	CircleSprite tempCircle{ 1, *PacManPosition };
	auto pos = GetPosition();
	if (Collision::CheckCollision(WithinRangeCircle, tempCircle))
	{
		Navigator.SetTarget(*PacManPosition);
	}
	else if (RedGhostPositionIsSet)
	{
		auto grad = (RedGhostPosition->Y -PacManPosition->Y) / (RedGhostPosition->X - PacManPosition->X);
		auto X = PacManPosition->X + (PacManPosition->X - RedGhostPosition->X)/3;
		auto C = RedGhostPosition->Y - grad * (RedGhostPosition->X);
		//straight line equation
		auto Y = grad * X + C;
		Navigator.SetTarget(Vector2(X, Y));
	}
	else
		Navigator.SetTarget(*PacManPosition);
}