#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <string>
#include "SplashScreen.h"
#include "../Data/ModelViews.h"
#include "Animation.h"
#include "GameEndScreen.h"
#include "../Logic/FileReader.h"

using std::string;
using std::vector;


/**
* @class FaildeToLoadResourceException
* @brief This class is responsible for throwing an exeption when no resource is loaded
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/


class FaildeToLoadResourceException
{
};
/**
* @class Render
* @brief This class is responsible for rendering all the enties to be displayed on the window
* @author Dembe Munyai and Kaddy Marindi
* \version 3.0
*/

class Render
{
public:

        /**\brief Parameterized Constructor. Creates object of Render
       *\param window of type RenderWindow
       */

	Render(const std::shared_ptr<sf::RenderWindow>& window);


    void RenderStaticRectangularEntitys(const std::vector<StaticEntitesViewModel>& StaticEntitesViewModel);
    void RenderText(const TextModelView& textModelView);
    void RenderGhost(const vector<GhostModelView>& ghostModelView, const float& deltaTime);
    void RenderPacMan(const PacManViewModel& PacManViewModel, const float& deltaTime);
    void RenderSplashScreen();
   // void RenderGameEndScreen(const unsigned int& Level, const string& textMessage, bool haveWon = true);
    void ClearWindow();
private:

	std::shared_ptr<sf::RenderWindow> window;
    //SplashScreen SplashScreen_;
   // GameEndScreen GameEndScreen;
    sf::Texture PacManTexture;
    sf::Texture GhostsTexture;
    sf::Texture FruitsTextutre;
    sf::Texture keyTexture;
    //sf::RectangularEntity FruitRectangularEntity;

    sf::RectangleShape PackManRectangularEntity;
    sf::RectangleShape GhostRectangularEntity;
    sf::RectangleShape Wall;
    sf::RectangleShape Door;
    sf::RectangleShape Fruit;
    sf::RectangleShape Key;
    sf::CircleShape Pallet;

    sf::Font font;
    sf::Text ScoreText;
    sf::Text LevelText;
    sf::Text HighestScoreText;
    sf::Text GeneralText;

    Animation GhostAnimation;
    Animation PacManAnimation;


private:
    void RenderRectangleShape(const StaticEntitesViewModel& modelView,sf::RectangleShape& rect);
    void RenderWall(const StaticEntitesViewModel& StaticEntitesViewModel);
    void RenderKeys(const StaticEntitesViewModel& StaticEntitesViewModel);
    void RenderFruits(const StaticEntitesViewModel& StaticEntitesViewModel);
    void Initialise();
    //void RenderGhosts(const std::vector<StaticEntitesViewModel>& StaticEntitesViewModel);
    //void RenderPacMan(const std::vector<StaticEntitesViewModel>& StaticEntitesViewModel);

};


