#pragma once
#include <string>
#include "Vector2.h"
#include "Definitions.h"

using std::string;

class TextModelView
{
public:
    string Level;
    string Lives;
    string HighestScore;
    string CurrentScore;
    int highscore_;
    int currentscore;
};

class StaticEntitesViewModel
{
public:
    std::string Title;
    Vector2 Positon;
    Vector2 Dimention;
};

class GhostModelView : public StaticEntitesViewModel
{
public:
    Mode Mode;
};

class PacManViewModel : public StaticEntitesViewModel
{
public:
    Direction Direction;
    State State;
};
