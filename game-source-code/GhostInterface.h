#pragma once
#include "CircleSprite.h"
#include "Movement.h"
#include "GhostNavigator.h"

class GhostInterface: public CircleSprite
{
public:
private:
	GhostNavigator GhostNavigator;
};

