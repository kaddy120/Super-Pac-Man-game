#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Window
{
public:
	//i should make this window a singleton; 
	Window(): window_(new sf::RenderWindow(sf::VideoMode(800, 1000, 32),
		"Duel Invaders", sf::Style::Titlebar | sf::Style::Close)) {

		window_->setVerticalSyncEnabled(true);
		window_->setFramerateLimit(60);
	}

	std::shared_ptr<sf::RenderWindow> getWindow() {	
		return window_;
	}
private:
	std::shared_ptr<sf::RenderWindow> window_;
};

