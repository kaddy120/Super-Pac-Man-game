#pragma once
#include "ModelViews.h"
#include "../Logic/AbstractGhost.h"
#include "../Logic/PacMan.h"
#include "../Logic/CircularEntity.h"
#include "../Logic/RectangularEntity.h"
#include <vector>
#include <memory>
#include <string>
#include "../Logic/Definitions.h"

/**
* @class MapEntitiesToDTO
* @brief This class is responsible for maooing all the entities
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/

using std::vector;

//DTO stand for Data Transfer Object
class MapEntitiesToDTO
{
public:
	static void MapTextViewModel(TextModelView& modelView, const PacMan& pacMan, const int& highestScore, const unsigned int& level);
	static void MapPacManViewModel(PacManViewModel& modelView, const PacMan& pacMan, const Direction& currentDirection);
	static void MapGhostModelView(vector<GhostModelView>& modelView, const vector<std::unique_ptr<AbstractGhost>>& Ghosts);
	static void MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const vector<RectangularEntity>& rectRectangularEntity );
	static void MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const CircularEntity& CircularEntity);
	static void MapStaticEntitiesModelView(vector<StaticEntitesViewModel>& modelView, const RectangularEntity& rectRectangularEntity);
};

