#pragma once
#include "AbstractGhost.h"
/**
 *@class YellowGhost
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This class is responsible for checking and for controling the Yellow ghost,
 the class inherits from the AbstractClass.
 \version 3.0

*/
class YellowGhost: public AbstractGhost
{
public:

    /**
    * @brief The paramiterised consonstructor is used to initialise the Ghost
    * @param turningTiles  are used by the ghost to generate new target when the new possible path is available
    * @param walls  are used to build up the maze,the pacman and the ghost cannot go through
    * @param Doors  build up the maze,pacman and the ghost can only go through it unless it is unlocked
    * @param radius   radius/dimension of the ghost
    * @param initPosition initial postion of the ghost whenever the game begins
    */

	YellowGhost(
		const std::vector<CircularEntity>& turningTiles,
		const std::vector<RectangularEntity>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius = 20.f,
		const Vector2& initPosition = Vector2(320, 380));

    /**
    * @brief The function is takes the current position of the Pac-man and sets the target
    * @param position,this parameter is a shared pointer used to pass the current position of the Pac-man
    * \return void
    */


	    void SetPackManPosition(const std::shared_ptr<Vector2>& position) override;

private:
	void SetTarget() override;
	Vector2 PacManPreviousPosition;
	//std::shared_ptr<Vector2> PacManPostion;  //redPacManPosition
	std::chrono::steady_clock::time_point StartTime = std::chrono::steady_clock::now();
};

