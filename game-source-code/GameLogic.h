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
#include "Render.h"

using std::vector;

class GameLogic
{
public:
	GameLogic(std::shared_ptr<sf::RenderWindow> window);
	void Run();
	void Quit();
private:
	void UpdateEntities();
	void RenderEntities();
	void MapEntitiesToModelView();
	bool IsGameOver();
	void Initialise();

private:
	Render Render_;
	PacMan PacMan_;
	Direction PacManCurrentDirection;
	Direction ProposedDirection;
	bool proposed = true;
	std::vector<std::unique_ptr<AbstractGhost>> Ghosts;
	std::shared_ptr<sf::RenderWindow> window;
	//should go.
	float deltaTime = 0.f;
	unsigned int Level = 0;
	bool IsGameOver_;
	Clock Clock_;

	vector<Sprite> walls;
	vector<CircleSprite> TurningPoints;
	vector<std::shared_ptr<Door>> Doors;
	Door GhostsHouseDoor;
	vector<SuperPallet> SuperPallets;
	vector<SuperPallet> PowerPallets;
	vector<Key> Keys;
	vector<Fruit> Fruits;

	TextModelView textModelView;
	vector<GhostModelView> ghostModelView;
	vector<SpriteModelView> StaticEntityModelView;
	PacManModelView pacManModelVIew;
};

