#pragma once
#include <memory>
#include <vector>
#include "RectangularEntity.h"
#include "Door.h"
#include "Movement.h"
#include "Collision.h"

/**
 *@class GhostNavigator
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This is the ghost navigator for all the ghosts.The main objective is to make decisions for all the 4 ghosts.
 The class tells the ghosts where to turn,where to go and set the target.
 \version 3.0
*
*
*/



//think of this as real navigator that is navigating game maze
class GhostNavigator
{
public:
	GhostNavigator(
		std::vector<CircularEntity> TurningTiles,
		std::vector<RectangularEntity> Walls,
		std::vector<std::shared_ptr<Door>> Doors,
	    std::shared_ptr<Vector2> ghostPosition_ptr);
    /**
    * @brief The function helps the ghost to find the target

    *  @return void
    */
    void FindDirectionToTarget();
      /**
    * @brief The function generates random direction for some of the ghost

    *  @return void
    */
	void RandomDirection();
    /**
    * @brief This function checks if the ghost is at the turning tile
    ,this helps the ghost to generate the new target

    *  @return bool
    */
	bool isInsideTurningTiles();

	 /**
    * @brief This function sets the current direction of the Pac-man

    *  @return void
    */
	void SetCurrentDirection(const Direction& direction);
	Direction GetCurrentDirrection() const;
	 /**
    * @brief This function is responsibe to give the ghost a target position

    *  @return void
    */
	void SetTarget(const Vector2& target);
private:

	std::vector<CircularEntity> TurningTiles;
	std::vector<RectangularEntity> Walls;
	std::vector<std::shared_ptr<Door>> Doors;
	std::shared_ptr<Vector2> GhostPosition_ptr;
	Vector2 Target;
	int StuckCount = 0;
	Direction CurrentDirection = Direction::Up;
	bool isSelectedDirectionMovable(const Direction& direction);
	bool CheckCollisionWithaDoor(const RectangularEntity& rectangle) const;
};








