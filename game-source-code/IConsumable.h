#pragma once
/**
 @class IConsumable
 @author Dembe Munyai and Kaddy Marindi
 @brief The main objective of this class is to control all the consumable entities such as pellets and fruits.

 \version 3.0
*
*
*/

class IConsumable {
public:

     /** \brief This is a Virtual functions that
         *  returns number of points or scores
         *  \return number of points
         */
	virtual unsigned int GetPoints() const = 0;
	 /** \brief This is a Virtual functions that
         *  sets number  of points to each entinity  that is consumable
         *  \return an int containing points
         */
	virtual void SetPoints(const unsigned int& points) = 0;
};
