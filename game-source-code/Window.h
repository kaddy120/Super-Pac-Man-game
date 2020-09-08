#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Window
{
public:
	//i should make this window a singleton; 
	Window() {
		std::shared_ptr<sf::RenderWindow> window(new sf::RenderWindow(sf::VideoMode(800, 1000, 32),
			"Duel Invaders", sf::Style::Titlebar | sf::Style::Close));
		window_ = window;
	}

	std::shared_ptr<sf::RenderWindow> getWindow() {	
		return window_;
	}
private:
	std::shared_ptr<sf::RenderWindow> window_;
};

