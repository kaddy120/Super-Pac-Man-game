#pragma once
#include "CircleSprite.h"
#include "IConsumable.h"
/**
* @class SuperPallet
* @brief This class is responsible for all the SupperPellet and PowerPellet Entities in the game
*each Pellet has minimum of 50 points in the first level of the game.
The class inherits  from the Iconsumable and the CircleSprite class.
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/


class SuperPallet: public CircleSprite, public IConsumable
{
public:


     /** \brief Parameterized Constructor. Creates SuperPallet object.
         *  \param radius of type float ,gives a radius dimension of the  of the SuperPallet entitiry.
            \param Position is of type vector2.Sets the position of each SuperPallet on the maze
             \param points of type const unsigned int, the points per each SuperPallet entitiry.
          *
         */

	SuperPallet(const float& radius, const Vector2& postion, const unsigned int& points = 50);


    /**
    * @brief The function is used to get points per pellet

    *  @return int
    */

	unsigned int GetPoints() const override;

    /**
    * @brief The function is used to set points per pellet
    * @param int,a point can only be of type int
    *  @return void
    */
	void SetPoints(const unsigned int& points) override;
private:
	unsigned int Points_;
};
