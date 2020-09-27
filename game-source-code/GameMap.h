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

//#include <memory>
using std::vector;

class GameMap
{
public:
	GameMap();
	vector<Sprite> GetWalls() const;
	vector<CircleSprite> GetTurningPoinints() const;
	vector<std::shared_ptr<Door>> GetDoors() const;
	vector<Key> GetKeys() const;
	vector<Fruit> GetFruits() const;
	vector<SuperPallet> GetSuperPallets() const;
	vector<SuperPallet> GetPowerPallets() const;

private:
	vector<std::vector<std::string> > Maize;
	vector<Sprite> Walls;
	vector<std::shared_ptr<Door>> Doors;
	vector<Fruit> Fruits;
	vector<Key> Keys;
	vector<CircleSprite> TurningPoints;
	//i think i should rename super pallet to just pallet
	vector<SuperPallet> SuperPallets;
	vector<SuperPallet> PowerPallets;
	void Map();
	void AssignKeyToDoor();

};

