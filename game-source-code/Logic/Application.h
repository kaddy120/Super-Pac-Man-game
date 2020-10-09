#pragma once
#include <memory>
#include "Inputs.h"
#include "RedGhost.h"
#include "YellowGhost.h"
#include "PinkGhost.h"
#include "PacMan.h"
#include "GameMap.h"
#include "BlueGhost.h"
#include "MapEntitiesToDTO.h"
#include "FileReader.h"
#include "Clock.h"

using namespace std;
using std::vector;
/**
 *@class Application
 *@author Dembe Munyai and Kaddy Marindi
 *@brief Application perfom the interaction of the game entites to build the logic
 \version 3.0
*/
class Application
{
public:
      /**
    * @brief Default constructor to instatiate Application object
    */
	Application() = default;
	  /**
    * @brief Paramitarised contructor to instatiate Application object
    * @param walls is of type std::vector<RectangularEntity>. This is maze walls
    * @param Doors is of type std::vector<std::shared_ptr<Door>>. It's a vector of all the doors in the maze
    */
	Application(vector<RectangularEntity> walls, vector<std::shared_ptr<Door>> Doors);
	  /**
    * @brief MovePacMan function is responsible for moving Pac-man in respect to maze walls and doors
    * @param pacMan is of type PacMan. It's an instance of PacMan class
    * @param direction is of type Direction. It's the direction that Pac-Man should move to.
    *  @return void
    */
	void MovePacMan(PacMan& pacMan, const Direction& direction, const float& deltaTime);
	  /**
    * @brief MoveGhost function is for moving all the ghosts using one function.
    * @param Ghosts is of type std::vector<std::unique_ptr<AbstractGhost>>. It's vector container of pointer to all the ghosts.
    *  @return void
    */
	void MoveGhost(std::vector<std::unique_ptr<AbstractGhost>>& Ghosts, const float& deltaTime);
	  /**
    * @brief pacManAndGhostsCollide function is to check if ghosts and Pac-man collide. If they do and Pac-man state is Charged.
    A ghost that collide with Pac-man will be set to Eaten mode.
    * @param Ghosts is of type std::vector<std::unique_ptr<AbstractGhost>>. It's vector container of pointer to all the ghosts.

    *  @return returns true if pacMan and Ghosts collide. Else returns false
    */
	bool PacManAndGhostsCollide(const PacMan& pacMan, vector<std::unique_ptr<AbstractGhost>>& Ghosts);
	  /**
    * @brief EatFruits function is for pacMan to eat the fruits in the maze.
    pacMan points will be incremented if it eats a fruit and the eaten fruit is deleted.
    * @param pacMan is of type PacMan. pacMan is an instance of PacMan class.
    */
	void EatFruits(PacMan& pacMan, std::vector<Fruit>& fruits);
	  /**
    * @brief AtePallet function is for checking if pacMan ate a pellet. If pacMan ate a pellet, pacMan's points are increment
     and the pellet is deleted from a vector.
        * @param pacMan is of type PacMan. pacMan is an instance of PacMan class.
    *  @return returns true if pacMan ate a pellet
    */
	bool AtePallet(PacMan& pacMan, std::vector<Pellet>& pallet);
	  /**
    * @brief OpenDoors function is for opening the door(s) if pacMan eats a key.
    * @param pacMan is of type PacMan. pacMan is an instance of PacMan class.
    * @param keys are of type std::vector<Key>. keys is a vector that stores Key's object
    * @param Doors is of type vector<std::shared_ptr<Door>>. Doors is a vector of pointer to the Door's objects.
    *  @return void
    */
	void OpenDoors(const PacMan& pacMan, std::vector<Key>& keys, vector<std::shared_ptr<Door>>& Doors);
	  /**
    * @brief isProsedDirectionMovable fucntion is to check if pacMan can move in the provided direction in
     to the maze walls and doors.
    * @param pacMan is of type PacMan. pacMan is a PacMan's object.
    *  @return returns true if pacMan can move. Else return false
    */
	bool isProsedDirectionMovable(const PacMan& pacMan,const Direction& direction);
	  /**
    * @brief MovablesExitMaze function is to check an object that implement IEntity has exited maze. if so,
    the object should be placed on the opposite side of the maze. for an instance, is a Pac-Man exit maze using
    the right door. Pac-man should enter the maze on the opposite side door.
    * @param MovableEntity inherit from IEntity or inherit a chid of IEntity.
    * @param mazeWidth is of type uint. mazeWidth is the widht of the maze.
    *  @return void
    */
	void MovablesExitMaze(IEntity& MovableEntity,const unsigned int& mazeWidth);

private:
	vector<RectangularEntity> walls;
	vector<std::shared_ptr<Door>> Doors;
};

