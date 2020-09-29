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

//DTO stand for Data Transfer Object
class MapEntiesToDTO
{
public:
	static void MapTextModelView(TextModelView& modelView, const PacMan& pacMan, const vector<std::string>& fromFile);
	static void MapPacManModelView(PacManModelView& modelView, const PacMan& pacMan, const Direction& currentDirection);
	static void MapGhostModelView(vector<GhostModelView>& modelView, const vector<std::unique_ptr<AbstractGhost>>& Ghosts);
	static void MapStaticEntitiesModelView(vector<SpriteModelView>& modelView, const vector<Sprite>& rectSprite );
	static void MapStaticEntitiesModelView(vector<SpriteModelView>& modelView, const CircleSprite& circleSprite);
	static void MapStaticEntitiesModelView(vector<SpriteModelView>& modelView, const Sprite& rectSprite);
};

