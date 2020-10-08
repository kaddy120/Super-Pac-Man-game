#pragma once
#include "Collision.h"
#include "fruit.h"
#include "Door.h"
#include "Sprite.h"
#include "Door.h"
#include "Key.h"
#include <vector>
#include <iostream>
#include "CircleSprite.h"
#include "SuperPallet.h"
/**
 *@class GameMap
 *@author Dembe Munyai and Kaddy Marindi
 *@brief The class is resposnble for constructing the game Maze.
 all the maping of the entities are mapped into the maze from the vector.All the entities are a vector of that type.
 \version 3.0
*
*
*/

//#include <memory>
using std::vector;

class GameMap
{
public:
    /**
    * @brief The default constructor creates a GameMap object

    *
    */


	GameMap();

	    /**
    * @brief All the entities below are mapped into the game map from a vector
    the const per entitiy is done to ensure that no modififaction can take place

    *
    */


	vector<Sprite> GetWalls() const;
	vector<CircleSprite> GetTurningPoinints() const;
	vector<std::shared_ptr<Door>> GetDoors() const;
	vector<Key> GetKeys() const;
	vector<Fruit> GetFruits() const;
	vector<SuperPallet> GetSuperPallets() const;
	vector<SuperPallet> GetPowerPallets() const;

	    /**
    * @brief This is an entity responsible for the Ghost house door.
    */
	Door GhostsHouseDoor() const;
private:
	vector<std::vector<std::string> > Maize;
	vector<Sprite> Walls;
	vector<std::shared_ptr<Door>> Doors;
	Door GhostsHouseDoor_;
	vector<Fruit> Fruits;
	vector<Key> Keys;
	vector<CircleSprite> TurningPoints;
	//i think i should rename super pallet to just pallet
	vector<SuperPallet> SuperPallets;
	vector<SuperPallet> PowerPallets;
	void Map();
	void AssignKeyToDoor();

};

