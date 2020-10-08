#pragma once
#include "AbstractGhost.h"

/**
 @class PinkGhost
 @author Dembe Munyai and Kaddy Marindi
 @brief This class is responble for checking for controling the Pink ghost,
 The class inherits from the AbstractClass
*
*
*/
class PinkGhost: public AbstractGhost
{
public:
       /**
    * @brief The paramiterised consonstructor is used to initialise the Ghost
    * @param turningTiles  are used by the ghost to generate new target when the new possible path is available
    * @param walls  are used to build up the maze,the pacman and the ghost cannot go through
    * @param Doors  build up the maze,pacman and the ghost can only go through it unless it is unlocked
      @param radius   radius/dimension of the ghost
      @param initPosition initial postion of the ghost whenever the game begins

    */
	PinkGhost(
		const std::vector<CircleSprite>& turningTiles,
		const std::vector<Sprite>& walls,
		const std::vector<std::shared_ptr<Door>>& Doors,
		const std::shared_ptr<Vector2>& RedGhostposition,
		const float& radius = 20.f,
		const Vector2& initPosition = Vector2(320, 380));



private:
	void SetTarget();
	bool RedGhostPositionIsSet = false;
	std::shared_ptr<const Vector2> RedGhostPosition;
	//this need refactoring;
	Vector2 ScatterPosition = Vector2(0.f, 0.f);


};

