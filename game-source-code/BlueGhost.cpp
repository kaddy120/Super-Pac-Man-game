#include "BlueGhost.h"
#include <iostream>

BlueGhost::BlueGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
	const std::vector<std::shared_ptr<Door>>& Doors,
	const float& radius,
	const Vector2& initPosition) : AbstractGhost(turningTiles,walls, Doors, radius,initPosition) {
	ScatterPosition = Vector2(0, 900.f);
	this->Name("BlueGhost");
}

void BlueGhost::SetTarget()
{
	Navigator.SetTarget(*PacManPosition);
}

