#pragma once
#include "ModelViews.h"
#include "AbstractGhost.h"
#include "PacMan.h"
#include "CircleSprite.h"
#include "Sprite.h"
#include <vector>
#include <memory>
#include "Definitions.h"

using std::vector;

class MapEntiesToDTO
{
public:
	static void MapTextModelView(TextModelView& modelView, const PacMan& pacMan, const vector<std::string>& fromFile);
	static void MapPacManModelView(PacManModelView& modelView, const PacMan& pacMan, const Direction& currentDirection);
	static void MapGhostModelView(vector<GhostModelView>& modelView, const vector<std::unique_ptr<AbstractGhost>>& Ghosts);
	/*static void MapStaticEntitiesModelView(vector<SpriteModelView>& modelView);
	static void MapStaticEntitiesModelView();*/
};

