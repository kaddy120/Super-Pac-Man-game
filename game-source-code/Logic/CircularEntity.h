#pragma once
#include "string"
#include "Vector2.h"
#include <memory>
#include "IEntity.h"
/**
* @class CircularEntity
*@author Dembe Munyai and Kaddy Marindi
*@brief CircularRectangularEntity is responsible for all circular objects with a radius and powssition which is the center.
*\version 3.0
*/
class CircularEntity: public IEntity
{
public:

    /** \brief Parameterized Constructor. Creates  CircularEntity object.
    */
	CircularEntity();
	/** \brief Parameterized Constructor. Creates  CircularEntity object.
    * \param radius of type float  made for circular entity
    * \param Position is of type vector2.Sets the position of the circular entity.
    */
	CircularEntity(const float& radius, const Vector2& postion);



	 /**
    * @brief this function gets a position of CircularEnity object's position.
    * @
    *  @return a position of type vector2
    */

	Vector2 GetPosition() const override;

/**
    * @brief This function gets a shared pointer to the CircularEntity objects's center position
    * @
    *  @return returns a shared pointer to the center position
    */

	std::shared_ptr<Vector2> GetPosition_ptr() const override;

    /**
    * @brief Sets a Position for a all the circular entities
    * @param Position,Position is a variable of type Vector2
    *  @return void
    */
	void SetPosition(const Vector2& position) override;

    /**
    * @brief Getter function ,responsible for returning a radius of a circular RectangularEntity
    *
    *  @return float ,returns a float of type float
    */
	float GetRadius() const;
    /**
    * @brief Sets a radius of a circular entities
    * @param radius,radius of type float
    *  @return void
    */
	void SetRadius(const float& radius);
    /**
    * @brief sets a name of an entity
    *  @return string name
    */
	const std::string& Name() const { return name; }
    /**
    * @brief returns a name of an entity
    *  @return void
    */
	void Name(const std::string& name_) { name = name_; }

private:
	std::string name = "";
	float Radius;
	std::shared_ptr<Vector2> PositionCenter;
};

