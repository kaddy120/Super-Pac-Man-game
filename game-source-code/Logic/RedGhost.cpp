#include "RedGhost.h"
#include <iostream>

RedGhost::RedGhost(
	const std::vector<CircularEntity>& turningTiles,
	const std::vector<RectangularEntity>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : AbstractGhost(turningTiles,walls, Doors, radius,initPosition) {
	ScatterPosition = Vector2(600, 900.f);
	this->Name("RedGhost");
}

void RedGhost::SetTarget()
{
	Navigator.SetTarget(*PacManPosition);
}

