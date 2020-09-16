#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <string>
#include "Vector2.h"
#include "SplashScreen.h"

using std::string;
using std::vector;

class FaildeToLoadResourceException
{
};

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

};

class PacManModelView : public SpriteModelView
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
    //SplashScreen SplashScreen_;
    sf::Texture PacManTexture;
    sf::Texture GhostsTexture;
    sf::Texture FruitsTextutre;
    sf::Texture keyTexture;
    sf::Sprite FruitSprite;
    sf::Sprite PackManSprite;
    sf::Sprite GhostSprite;
    sf::RectangleShape Wall;
    sf::RectangleShape Door;


    sf::Font font;
    sf::Text Score;
    sf::Text Level;
    sf::Text HighestScore;
    sf::Text GeneralText;

private:
    void RenderDoors(const std::vector<SpriteModelView>& spriteModelView);
    void RenderKeys(const std::vector<SpriteModelView>& spriteModelView);
    void RenderFruits(const std::vector<SpriteModelView>& spriteModelView);
    void Initialise();
    //void RenderGhosts(const std::vector<SpriteModelView>& spriteModelView);
    //void RenderPacMan(const std::vector<SpriteModelView>& spriteModelView);

};


