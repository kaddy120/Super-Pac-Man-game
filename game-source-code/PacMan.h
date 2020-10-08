#pragma once
#include "Sprite.h"
#include "Movement.h"
#include "Definitions.h"
/**
* @class PacMan
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
* @brief The class controls the Pacman and it inherits from the Sprite class.
The class manages incrementing and decrementing of points and the lives of the PacMan.
*/


class PacMan: public Sprite
{
public:
       /** \brief Parameterized Constructor. Creates  Pacman object.
         *  \param width of type float gives width of the Pac-man sprite
             \param height of type float gives height of the Pac-man entity.
          *  \param Position is of type vector.Sets the position of the Pac-man.
         */


	PacMan(const float& width, const float& height, const Vector2& postion);

	 /**
    * @brief The function sets the speed of the Pac-man
      @param speed of type float.
    *  @return void
    */

	void SetSpeed(const float& speed);
		 /**
    * @brief Increaments the points whenever there is collision between Pac-man and consumable entities
      @param points of type unsigned int.Points can only be of type int.
    *  @return unsigned int
    */
    unsigned int IncreamentPoints(const unsigned int& points);
    	 /**
    * @brief A getter function that returns collected points.
      @return unsigned int
    */
	unsigned int GetPoints() const { return CollectedPoints; }
	    	 /**
    * @brief A function checks that sets the state of the Pacman.When the Super pellets is eaten
    @param state of type State.state of the pacman
      @return void
    */
	void SetState(const State& state);

	State GetState() const;
    /**
    * @brief A function responsible for keeping track of lives remaining.
      @return unsigned int.
    */
	unsigned int GetLifes() const;
	Vector2 Move(const Direction& direction);
    /**
    * @brief The function is responsible for destroying the Pac-man when the lives remaining are 0

      @return void
    */
	void Die();
	 /**
    * @brief Resets the colled points to 0.when the game is now over.

      @return void
    */
	void ResetPoints() { CollectedPoints = 0; }

private:
	unsigned int CollectedPoints=0;
	unsigned int Lifes = 3;
	State state=State::Alive;
	Movement Movement_;
};

