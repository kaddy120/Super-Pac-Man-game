#pragma once
#include "Sprite.h"
#include "string"

enum class Mode { Chase, Eatable, InTheBox, Captured };

class Ghost : public Sprite
{
private: 
	std::string Colour;
	Mode Mode_;

};

