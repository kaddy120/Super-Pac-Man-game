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
	Application(std::shared_ptr<sf::RenderWindow> window);
	void Start();
	void MovePacMan(PacMan& pacMan, const Direction& direction, const float& deltaTime);
	void MoveGhost(std::vector<std::unique_ptr<AbstractGhost>>& Ghosts, const float& deltaTime);
	bool PacManAndGhostsCollide(const PacMan& pacMan, vector<std::unique_ptr<AbstractGhost>>& Ghosts);
	void EatFruits(PacMan& pacMan, std::vector<Fruit>& fruits);
	bool AtePallet(PacMan& pacMan, std::vector<SuperPallet>& pallet);
	void OpenDoors(const PacMan& pacMan, std::vector<Key>& keys, vector<std::shared_ptr<Door>>& Doors);
	bool isProsedDirectionMovable(
		const PacMan& pacMan,
		const Direction& direction,
		const vector<Sprite>& walls,
		const vector<std::shared_ptr<Door>>& Doors);

private:
	Render Render_;
	PacMan player1;
	Direction PacManCurrentDirection;
	Direction ProposedDirection;
	vector<Sprite> walls;
	vector<std::shared_ptr<Door>> Doors;
	vector<CircleSprite> TurningPoints;
	Door GhostsHouseDoor;
	vector<SuperPallet> SuperPallets;
	vector<SuperPallet> PowerPallets;
	vector<Key> Keys;
	vector<Fruit> Fruits;
	std::vector<std::unique_ptr<AbstractGhost>> Ghosts;
	std::shared_ptr<sf::RenderWindow> window;
	TextModelView textModelView;
	vector<GhostModelView> ghostModelView;
	vector<SpriteModelView> StaticEntityModelView;
	PacManModelView pacManModelVIew;
	void MapEntitiesToModelView();
	float deltaTime = 0.f;
	bool proposed = true;
	unsigned int Level = 0;
	bool IsGameOver_;
	Clock Clock_;

private:
	void Update();
	void Render();
	void InitialiseEntities();
	//void InputHandler(const sf::Event& event);
	bool IsGameOver();
    void MovingToTheNextLevel();
	void MovablesExitMaize();
	void CheckGameEnd();
    //==All this functions below can be implemented in their own class
	void MapTextModelView();
	void MapStaticEntitiesModelView();
	void CloseGame();
};

