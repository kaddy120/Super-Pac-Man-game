#pragma once
#include "Sprite.h"
#include "string"

enum class Mode { Chase, Eatable, InTheBox, Captured };

class GhostAbstract : public Sprite
{
public:
	virtual void AmbushMovement() = 0;
	virtual void ChaseMovement() = 0;
	virtual void ScaredMovement() = 0;
	virtual void RandomMovement() = 0;
private: 
	std::string Colour;
	Mode Mode_;
	Vector2 Target;
};

