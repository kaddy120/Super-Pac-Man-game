#pragma once
#include <string>
#include "Vector2.h"

using std::string;

class TextModelView
{
public:
    string Level;
    string Lifes;
    string HighestScore;
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

};

class PacManModelView : public SpriteModelView
{
public:


};
