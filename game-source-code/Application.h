#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Inputs.h"
#include "RedGhost.h"
#include "YellowGhost.h"
#include "PinkGhost.h"
#include "PacMan.h"
#include "Window.h"
#include "GameMap.h"
#include "SplashScreen.h"
#include "Render.h"
#include "BlueGhost.h"
#include "MapEntiesToDTO.h"
#include "FileReader.h"
#include "Clock.h"

using namespace std;
using std::vector;

class Application
{
public:
	Application() = default;
	Application(vector<Sprite> walls, vector<std::shared_ptr<Door>> Doors);
	void MovePacMan(PacMan& pacMan, const Direction& direction, const float& deltaTime);
	void MoveGhost(std::vector<std::unique_ptr<AbstractGhost>>& Ghosts, const float& deltaTime);
	bool PacManAndGhostsCollide(const PacMan& pacMan, vector<std::unique_ptr<AbstractGhost>>& Ghosts);
	void EatFruits(PacMan& pacMan, std::vector<Fruit>& fruits);
	bool AtePallet(PacMan& pacMan, std::vector<SuperPallet>& pallet);
	void OpenDoors(const PacMan& pacMan, std::vector<Key>& keys, vector<std::shared_ptr<Door>>& Doors);
	bool isProsedDirectionMovable(const PacMan& pacMan,const Direction& direction);
	void MovablesExitMaze(CircleSprite& MovableEntity,const unsigned int& mazeWidth);
	void MovablesExitMaze(Sprite& MovableEntity,const unsigned int& mazeWidth);

private:
	vector<Sprite> walls;
	vector<std::shared_ptr<Door>> Doors;
};

