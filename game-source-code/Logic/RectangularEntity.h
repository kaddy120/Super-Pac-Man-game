#pragma once
#ifndef RectangularEntity_h
#define RectangularEntity_h
#include "Vector2.h"
#include <tuple>
#include "string"
#include <memory>
#include "IEntity.h"
/**
 *@class RectangularEntity
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This class is responsible for all the rectangular sprites.Each entity or sprite is give a width,height and a position
 \version 3.0
*/
class RectangularEntity: public IEntity
{
public:

    /** \brief Parameterized Constructor. Creates RectangularEntity object.
    */
	RectangularEntity();

    /** \brief Parameterized Constructor. Creates  RectangularEntity object.
    * \param radius of type float  made for circular entity
    * \param Position is of type vector2.Sets the position of the circular entity.
    */
	RectangularEntity(const float& width, const float& height, const Vector2& postion);

	/**
    * @brief This function gets a shared pointer to the RectangularEntity position
    * @
    *  @return returns a shared pointer to the position
    */

	std::shared_ptr<Vector2> GetPosition_ptr() const override;

    /**
    * @brief Sets a Position for a all the rectangular entities
    * @param Position,Position is a variable of type Vector2
    *  @return void
    */
	void SetPosition(const Vector2& position) override;

	Vector2 GetPosition() const override;
	/**
    * @brief getter function for getting a center of rectangular entities

    *  @return Vector2
    */
	Vector2 GetCenter();
	//return {Heigh, Width}
	std::tuple<float, float> getDimentions() const;

	/**
    * @brief Sets dimensions for a all the rectangular entities
    * @param width of type float,height of type float
    *  @return void
    */
	void SetDimensions(const float& width, const float& height);
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
	std::string name ="";
	float Width;
	float Height;
	//relative to the upleft-conner
	std::shared_ptr<Vector2> position;
	Vector2 Center;
};

#endif

