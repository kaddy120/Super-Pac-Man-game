#pragma once
#include "fruit.h"
#include "Door.h"
#include "Sprite.h"
#include "Door.h"
#include "Key.h"
#include <vector>
#include <iostream>
#include "CircleSprite.h"

//#include <memory>
using std::vector;

class GameMap
{
public:
	GameMap();
	vector<Sprite> GetWalls() const;
	vector<CircleSprite> GetTurningPoinints() const;

private:
	void Map();
	vector<std::vector<std::string> > Maize;
	vector<Sprite> Walls;
	vector<Door> Door;
	vector<Fruit> Fruite;
	vector<Key> Keys;
	vector<CircleSprite> TurningPoints;
};

