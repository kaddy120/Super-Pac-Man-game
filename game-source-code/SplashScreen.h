#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class SplashScreen
{
public:
	SplashScreen(std::shared_ptr<sf::RenderWindow>& window);
private:
	sf::Text pauseMessage;
	sf::Texture file_image;
};

