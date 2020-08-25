#pragma once
#include "fruit.h"
#include "Door.h"
#include "Sprite.h"
#include "Door.h"
#include "Key.h"
#include <vector>
//#include <memory>

class GameMap
{
public:
	GameMap();

private:
	//if i'm not storing all this in one container, why am i even using smart pointer?
	// i ma
	//std::shared_ptr<Sprite> Walls;
	//std::shared_ptr<Door> Door;
	//std::shared_ptr<Fruit> Fruite;
	//std::shared_ptr<Key> Keys;

	std::vector<Sprite> Walls;
	std::vector<Door> Door;
	std::vector<Fruit> Fruite;
	std::vector<Key> Keys;
};

