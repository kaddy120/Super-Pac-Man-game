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
#include "MapEntitiesToDTO.h"
#include "FileReader.h"
#include "Clock.h"
#include "Render.h"
#include "Application.h"

class GameLogic
{
public:
	//GameLogic(
	//	const GameMap& gameMap,
	//	std::shared_ptr<sf::RenderWindow> window,
	//	const PacMan& pacMan,
	//	std::vector<std::unique_ptr<AbstractGhost>> Ghosts);
	GameLogic(std::shared_ptr<sf::RenderWindow> window);
	void Run();
private:
	void Update();
	void RenderEntities();
	void InitialiseEntities();
	bool IsGameOver();
	void MovingToTheNextLevel();
	void MovablesExitMaize();
	void CheckGameEnd();
	void MapTextViewModel();
	void MapStaticEntitiesViewModel();
	void CloseGame();

private:
	PacMan pacMan;
	vector<Sprite> walls;
	vector<std::shared_ptr<Door>> Doors;
	vector<CircleSprite> TurningPoints;
	Direction ProposedDirection;
	vector<Key> Keys;
	vector<Fruit> Fruits;
	Door GhostsHouseDoor;
	vector<SuperPallet> PowerPallets;
	std::vector<std::unique_ptr<AbstractGhost>> Ghosts;

	Direction PacManCurrentDirection;
	vector<SuperPallet> SuperPallets;
	Render Render_;
	Application Logic;
	std::shared_ptr<sf::RenderWindow> window;
	TextModelView textModelView;
	vector<GhostModelView> ghostModelView;
	vector<StaticEntitesViewModel> StaticEntityModelView;
	PacManViewModel PacManViewModel;
	void MapEntitiesToModelView();
	float deltaTime = 0.f;
	bool proposed = true;
	unsigned int Level = 0;
	bool NextLevel = false;
	bool IsGameOver_;
	Clock Clock_;
};

