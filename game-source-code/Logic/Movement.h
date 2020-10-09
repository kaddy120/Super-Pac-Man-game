#pragma once
#include "Vector2.h"
#include <memory>
#include "Definitions.h"
/**
 *@class Movement
 *@author Dembe Munyai and Kaddy Marindi
 *@brief The responsibilty is to control all the movements of the game,
 most of the entinty classes inherit from thid class.
 \version 3.0
*
*
*/

class Movement
{
public:
     /**
    * @brief The paramiterised constructor creates Movement object.
    * @param
    */
	Movement(const float& speed = 1.8f);
   /** \brief Function sets the speed of all moving object
    *
    *@param speed of type float.
    *\return void
    */
	void SetSpeed(const float& speed);


	Vector2 Move(std::shared_ptr<Vector2> Position, const Direction& direction);

private:
	float Speed;
};
