#pragma once
#include <memory>
#include <vector>
#include "Sprite.h"
#include "Door.h"
#include "Movement.h"  ///this is just temporary
#include "Collision.h"

//think of this as real navigator that is navigating game maze
class GhostNavigator
{
public:
	GhostNavigator(
		std::vector<CircleSprite> TurningTiles,
		std::vector<Sprite> Walls,
		std::vector<std::shared_ptr<Door>> Doors,
	    std::shared_ptr<Vector2> ghostPosition_ptr);

    void FindDirectionToTarget();
	void RandomDirection();
	//Direction FindDirectionInScaredMode();
	bool isInsideTurningTiles();
	void SetCurrentDirection(const Direction& direction);
	Direction GetCurrentDirrection() const;
	void SetTarget(const Vector2& target);
private:

	std::vector<CircleSprite> TurningTiles;
	std::vector<Sprite> Walls;
	std::vector<std::shared_ptr<Door>> Doors;
	std::shared_ptr<Vector2> GhostPosition_ptr;
	Vector2 Target;
	int StuckCount = 0;
	Direction CurrentDirection = Direction::Up;
	bool isSelectedDirectionMovable(const Direction& direction);
	bool CheckCollisionWithaDoor(const Sprite& rectangle) const;
};








