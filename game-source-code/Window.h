#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
/**
 *@class Window
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This class is responsible for displaying all the drawings.Classes such as GameEnd,Splash Screen and render depends on on this class
 *\version 3.0
*/
class Window
{
public:

	Window(): window_(new sf::RenderWindow(sf::VideoMode(780, 1000, 32),
		"Super Pacman", sf::Style::Titlebar | sf::Style::Close)) {

		window_->setVerticalSyncEnabled(true);
		window_->setFramerateLimit(60);
	}
    /**
    * @brief This functions is responsible for generating a window
    * \return returns a std::shared_ptr to sf::RenderWindow
    */
	std::shared_ptr<sf::RenderWindow> getWindow() {
		return window_;
	}
private:
	std::shared_ptr<sf::RenderWindow> window_;
};

