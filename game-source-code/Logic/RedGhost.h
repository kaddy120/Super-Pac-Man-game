#pragma once
#include "AbstractGhost.h"
/**
 @class RedGhost
 @author Dembe Munyai and Kaddy Marindi
 @brief This class is responble for checking for controling the Red ghost,
 The class inherits from the AbstractClass
*
*
*/

class RedGhost: public AbstractGhost
{
public:
        /**
    * @brief The paramiterised consonstructor is used to initialise the RedGhost object
    * @param turningTiles  turningTiles  are used by the ghost to generate new target when the new possible path is available
    * @param walls  are used to build up the maze,the pacman and the ghost cannot go through
    * @param Doors  build up the maze,pacman and the ghost can only go through it unless it is unlocked
      @param radius   radius/dimension of the RedGhost
      @param initPosition initial postion of the ghost whenever the game begins

    */
	RedGhost(
		const std::vector<CircularEntity>& turningTiles,
		const std::vector<RectangularEntity>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const float& radius = 20.f,
		const Vector2& initPosition = Vector2(320, 380));

private:
	void SetTarget() override;
};

