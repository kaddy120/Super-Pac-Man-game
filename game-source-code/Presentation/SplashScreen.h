#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
/**
 *@class SplashScreen
 *@author Dembe Munyai and Kaddy Marindi
 *@brief Class  responsible for the Splash screen with instruction to guide the use window.
 *The class gets the shared window from window class.
 *\version 3.0
*/
class SplashScreen
{
public:
      /**\brief Parameterized Constructor. .
       *\param window of type std::shared_ptr to sf::RenderWindow,
         * \return returns a std::shared_ptr to sf::RenderWindow
       */

	SplashScreen(std::shared_ptr<sf::RenderWindow>& window);
private:
	sf::Text pauseMessage;
	sf::Texture file_image;
};

