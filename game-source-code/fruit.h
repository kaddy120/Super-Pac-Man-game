#pragma once
#include "IConsumable.h"
/**
* @class Fruit
* @brief This class is responsible for all the fruits Entities in the game
*each fruits has minimum of 10 points in the first level of the game.The Fruit class inherits from the CircularEntity class
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/



class Fruit: public IConsumable,  public CircularEntity
{
public:
/** \brief Parameterized Constructor. Creates Fruit object.
         *  \param radius of type float ,gives a radius dimension of the  fruit entity.
            \param Position is of type vector2.Sets the position of each fruit on the maze

          *
         */

	Fruit(const float& radius, const Vector2& postion, const unsigned int& points = 10);

	         /**
    * @brief The function is used to get points per fruits

    *  @return int
    */

    unsigned int GetPoints() const override;

	         /**
    * @brief The function is used to set points per fruits
    * @param int,a point can only be of type int
    *  @return void
    */
    void SetPoints(const unsigned int& points) override;
private:
	unsigned int PointsPerFruit= 10;
};
