#pragma once
#include "Sprite.h"
#include <vector>
#include "CircleSprite.h"
/**
 @class Collision
 @author Dembe Munyai and Kaddy Marindi
 @brief This class is responble for checking collision between the Ghost and Pac-mam
*The class also checks collsions between the Pac-man and the keys through the maze
*
*
*/
class Collision
{
public:
      /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */


	static bool CheckCollision(const Sprite& firstRectangle, const Sprite& secondRectangle ); //square to square

    /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */

	static bool CheckCollision(const Sprite& firstSprite, const std::vector<Sprite>& secondSprite); //square to squares
	  /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */

	static bool CheckCollision(const CircleSprite& firstCircle, const CircleSprite& secondCircle); //circle to cicle
	  /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */
	static bool CheckCollision(const CircleSprite& circle, const std::vector<CircleSprite>& circles); //circle to circles
	  /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */
	static bool CheckCollision(const CircleSprite& circle, const Sprite& rectangle); //circle to rectangle
	  /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */
	static bool CheckCollision(const Sprite& rectangle, const std::vector<CircleSprite>& circles); //rectange and cicles
};

