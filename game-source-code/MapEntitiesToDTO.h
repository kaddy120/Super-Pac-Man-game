#pragma once
#include "ModelViews.h"
#include "AbstractGhost.h"
#include "PacMan.h"
#include "CircleSprite.h"
#include "Sprite.h"
#include <vector>
#include <memory>
#include <string>
#include "Definitions.h"

using std::vector;

//DTO stand for Data Transfer Object
class MapEntitiesToDTO
{
public:
	static void MapTextViewModel(TextModelView& modelView, const PacMan& pacMan, const int& highestScore, const unsigned int& level);
	static void MapPacManViewModel(PacManViewModel& modelView, const PacMan& pacMan, const Direction& currentDirection);
	static void MapGhostModelView(vector<GhostModelView>& modelView, const vector<std::unique_ptr<AbstractGhost>>& Ghosts);
	static void MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const vector<Sprite>& rectSprite );
	static void MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const CircleSprite& circleSprite);
	static void MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const Sprite& rectSprite);
};

