#pragma once
#include <memory>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class GameEndScreen
{
public:
	//for now i'll declare a font in here, but later i'll use one font from render
	GameEndScreen(const std::shared_ptr<sf::RenderWindow> window, const sf::Text& pauseMessage);
	void Render(const unsigned int& level, const std::string& message);
private:
	std::shared_ptr<sf::RenderWindow> Window_;
	const sf::Text Text;
		
};

