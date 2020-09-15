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

using namespace std;
using std::vector;

class Application
{
public:
	Application();
	void Start();

private:

	Render Render_;
	PacMan player1;
	Direction PacManCurrentDirection;
	vector<Sprite> walls;
	vector<CircleSprite> TurningPoints;
	vector<std::shared_ptr<Door>> Doors;
	vector<Key> Keys;
	vector<Fruit> Fruits;
	//Input Input;
	//std::vector<AbstractGhost> Ghosts;
	RedGhost redGhost;
	PinkGhost pinkGhost;
	YellowGhost yellowGhost;
	std::shared_ptr<sf::RenderWindow> window;
	SplashScreen SplashScreen_;

private:
	void Update();
	void Render();
	void InitialiseEntities();
	void MovePacMan();
	void MoveGhost();
	void CheckGameEnd();
	void EatFruits();
	void OpenDoors();
	void InputHandler(const sf::Event& event);
	bool IsGameOver();
	bool MovingToTheNextLevel();
	void MovablesExitMaize();

	/// --- this is temporary

     
};

