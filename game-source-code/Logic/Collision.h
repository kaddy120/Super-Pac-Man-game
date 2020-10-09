#pragma once
#include "RectangularEntity.h"
#include <vector>
#include "CircularEntity.h"
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


	static bool CheckCollision(const RectangularEntity& firstRectangle, const RectangularEntity& secondRectangle ); //square to square

    /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */

	static bool CheckCollision(const RectangularEntity& firstRectangularEntity, const std::vector<RectangularEntity>& secondRectangularEntity); //square to squares
	  /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */

	static bool CheckCollision(const CircularEntity& firstCircle, const CircularEntity& secondCircle); //circle to cicle
	  /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */
	static bool CheckCollision(const CircularEntity& circle, const std::vector<CircularEntity>& circles); //circle to circles
	  /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */
	static bool CheckCollision(const CircularEntity& circle, const RectangularEntity& rectangle); //circle to rectangle
	  /**
    * @brief The function checks the collision between two RectangularEntities and any object derived from RectangularEntity
    * @param firstRectangle
    * @param secondRectangle
    * @return bool
    */
	static bool CheckCollision(const RectangularEntity& rectangle, const std::vector<CircularEntity>& circles); //rectange and cicles
};

