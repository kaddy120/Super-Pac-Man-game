#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <string>
#include "SplashScreen.h"
#include "ModelViews.h"
#include "Animation.h"
#include "GameEndScreen.h"

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
    void RenderGhost(const vector<GhostModelView>& ghostModelView, const float& deltaTime);
    void RenderPacMan(const PacManModelView& pacManModelVIew, const float& deltaTime);
    void RenderSplashScreen();
    void RenderGameEndScreen(const unsigned int& Level, const string& textMessage, bool haveWon = true);
    void ClearWindow();
private:

	std::shared_ptr<sf::RenderWindow> window;
    //SplashScreen SplashScreen_;
   // GameEndScreen GameEndScreen;
    sf::Texture PacManTexture;
    sf::Texture GhostsTexture;
    sf::Texture FruitsTextutre;
    sf::Texture keyTexture;
    //sf::Sprite FruitSprite;

    sf::RectangleShape PackManSprite;
    sf::RectangleShape GhostSprite;
    sf::RectangleShape Wall;
    sf::RectangleShape Door;
    sf::RectangleShape Fruit;
    sf::RectangleShape Key;

    sf::Font font;
    sf::Text ScoreText;
    sf::Text LevelText;
    sf::Text HighestScoreText;
    sf::Text GeneralText;

    Animation GhostAnimation;
    Animation PacManAnimation;


private:
    void RenderRectangleShape(const SpriteModelView& modelView,sf::RectangleShape& rect);
    void RenderWall(const SpriteModelView& spriteModelView);
    void RenderKeys(const SpriteModelView& spriteModelView);
    void RenderFruits(const SpriteModelView& spriteModelView);
    void Initialise();
    //void RenderGhosts(const std::vector<SpriteModelView>& spriteModelView);
    //void RenderPacMan(const std::vector<SpriteModelView>& spriteModelView);

};


