#include "RedGhost.h"

RedGhost::RedGhost(
	std::vector<Sprite> turningTiles,
	std::vector<Sprite> walls,
	const float& width,
	const float& height,
	const Vector2& initPosition) : GhostAbstract(turningTiles,walls,width,height,initPosition) {}

void RedGhost::ChaseMovement()
{

}
