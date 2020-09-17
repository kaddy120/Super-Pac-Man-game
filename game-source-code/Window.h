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

		/*if (!font.loadFromFile("resources/sansation.ttf"));
		{
		}*/
	}

	std::shared_ptr<sf::RenderWindow> getWindow() {	
		return window_;
	}
private:
	std::shared_ptr<sf::RenderWindow> window_;
	//sf::Font font;
	/*sf::Text Score;
	Score.setFont(font);
	Score.setCharacterSize(30);
	Score.setPosition(20.f, 18.f);
	Score.setFillColor(sf::Color::White);*/
};

