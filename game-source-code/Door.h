#pragma once
#include "Sprite.h"
#include "Key.h"
#include "Vector2.h"
/**
* @class Door
* @brief This class is responsible for door entities in the game
*each door is assigned a position and a key.The class inherits from sprite
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/

class Door: public Sprite
{
public:

   /** \brief Default Constructor. Creates Door object.
    */

	Door();

        /** \brief Parameterized Constructor. Creates  Door object.
         *  \param width of type float gives width of the door entity.
             \param height of type float gives height of the door entity.
          *  \param Position is of type vector.Sets the position of each door on the maze
         */
	Door(const float& width, const float& height, const Vector2& postion);
  /**
    * @brief The function returns the key that is to be assigned to a door.

    *  @return Key
    */



	 Key GetKey() const { return key;}

    /**
    * @brief The function assign a door with a key

    *  @return void
    */

	void AssignKey(const Key& key);
	/**
    * @brief Checks if the door is assigned  with a key

    *  @return bool
    */
	bool HasKey() const;

	/**
    * @brief Checks if the door is assigned  with a key
       @param key is of type Key.
    *  @return bool
    */
	bool Unlock(const Key& key);

	/**
    * @brief Checks if the door is locked/closed

    *  @return bool
    */
	bool IsDoorLocked() const;

private:
	Key key;
	bool locked = true;
	bool hasKey = false;

};

