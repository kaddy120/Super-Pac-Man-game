#pragma once
#include <string>
#include "Vector2.h"
#include "Definitions.h"

using std::string;

class TextModelView
{
public:
    string Level;
    string Lifes;
    string HighestScore;
    string CurrentScore;
};

class SpriteModelView
{
public:
    std::string Title;
    Vector2 Positon;
    Vector2 Dimention;
};

class GhostModelView : public SpriteModelView
{
public:
    Mode Mode;
};

class PacManModelView : public SpriteModelView
{
public:
    Direction Direction;
};
