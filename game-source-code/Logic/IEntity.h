#pragma once
#include <memory>
#include "Vector2.h"
/**
 *@class IEntity
 *@author Dembe Munyai and Kaddy Marindi
 *@brief IEntity interface is inherited by CircularEntity and RectangularEntity
 \version 3.0
*/
class IEntity
{
public:
    	  /**
    * @brief GetPosition_ptr function returns a shared point to an IEntity position.
    */
	virtual std::shared_ptr<Vector2> GetPosition_ptr() const = 0;
		  /**
    * @brief GetPosition function is a virtua funtion that return a position
    * @return a position of type Vector2
    */
	virtual Vector2 GetPosition() const = 0;
		  /**
    * @brief Paramitarised contructor to instatiate Application object
    * @param walls is of type std::vector<RectangularEntity>. This is maze walls
    * @param Doors is of type std::vector<std::shared_ptr<Door>>. It's a vector of all the doors in the maze
    */
	virtual void SetPosition(const Vector2& position) = 0;
};
