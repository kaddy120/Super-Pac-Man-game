#pragma once
#include <memory>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
/**
 *@class GameEndscreen
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This class is responsible for the GameEnd window.This class gets the shared window from window class.
 *\version 3.0
*/
class GameEndScreen
{
public:
      /**\brief Parameterized Constructor. .
       *\param window of type RenderWindow
       *\param won,won is of type bool,checks if the Pac-man has won the game.
       */
	GameEndScreen(const std::shared_ptr<sf::RenderWindow>& window,const bool& won);

private:
//	std::shared_ptr<sf::RenderWindow> Window_;
//	const sf::Text Text;
	sf::Text pauseMessage;
	sf::Texture file_image;

};

