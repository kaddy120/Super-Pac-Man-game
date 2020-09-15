#include "RedGhost.h"
#include <iostream>

RedGhost::RedGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : AbstractGhost(turningTiles,walls, Doors, radius,initPosition) {
	ScatterPosition = Vector2(600, 900.f);
}

void RedGhost::SetTarget()
{
	Navigator.SetTarget(*PacManPosition);
}

