#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <string>
#include "Vector2.h"

using std::string;
using std::vector;

class FaildeToLoadResourceException
{
};

class Render
{
public:
	Render(const std::shared_ptr<sf::RenderWindow>& window);
    void RenderStaticSprites(const std::vector<SpriteModelView>& spriteModelView);
    void RenderText(const TextModelView& textModelView);
    void RenderGhost(const vector<GhostModelView>& ghostModelView);
    void RenderPacMan(const PacManModelView& pacManModelVIew);
    void RenderSplashScreen();
    void RenderEndGameScreen();
private:
	std::shared_ptr<sf::RenderWindow> window;
    sf::Texture PacManTexture;
    sf::Texture GhostsTexture;
    sf::Texture FruitsTextutre;
    sf::Texture keyTexture;

private:
    void RenderDoors();
    void RenderKeys();
    void RenderFruits();
    void RenderGhosts();
    void RenderPacMan();

};

class TextModelView
{
public:
    string Level;
    string Lifes;
    string HighestScore;
    string Level;
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

};

class PacManModelView : public SpriteModelView
{

};


