#pragma once
#include "CircularEntity.h"
#include "IConsumable.h"
/**
* @class Pellet
* @brief This class is responsible for all the SupperPellet and PowerPellet Entities in the game
*each Pellet has minimum of 50 points in the first level of the game.
The class inherits  from the Iconsumable and the CircularEntity class.
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/


class Pellet: public IConsumable, public CircularEntity
{
public:


     /** \brief Parameterized Constructor. Creates Pellet object.
         *  \param radius of type float ,gives a radius dimension of the  of the Pellet entitiry.
            \param Position is of type vector2.Sets the position of each Pellet on the maze
             \param points of type const unsigned int, the points per each Pellet entitiry.
          *
         */

	Pellet(const float& radius, const Vector2& postion, const unsigned int& points = 50);


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
