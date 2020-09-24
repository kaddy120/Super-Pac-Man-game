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
#include "FileReader.h"

using namespace std;
using std::vector;

class Application
{
public:
	Application(std::shared_ptr<sf::RenderWindow> window);
	void Start();

private:
	Render Render_;
	PacMan player1;
	Direction PacManCurrentDirection;
	Direction ProposedDirection;
	vector<Sprite> walls;
	vector<CircleSprite> TurningPoints;
	vector<std::shared_ptr<Door>> Doors;
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

private:
	void Update();
	void Render();
	void InitialiseEntities();
	void MovePacMan();
	void MoveGhost();
	void CheckGameEnd();
	void EatFruits();
	void OpenDoors();
	//void InputHandler(const sf::Event& event);
	bool IsGameOver();
    void MovingToTheNextLevel();
	void MovablesExitMaize();

    //==All this functions below can be implemented in their own class
	void MapTextModelView();
	void MapPacManModelView();
	void MapGhostModelView();
	void MapStaticEntitiesModelView();
	bool isProsedDirectionMovable();
	void CloseGame();

	/// --- this is temporary


};

