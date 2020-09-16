#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
public:
	Animation(sf::Texture* texture, const sf::Vector2u& imageCount, const float& switchTime);
	void Update(const unsigned int& row, const float& deltaTime);
	sf::IntRect GetIntRect();
private:
	sf::Vector2u ImageCount;
	sf::Vector2u CurrentImage;
	float TotalTime;
	float SwitchTime;
	sf::IntRect uvRect;
};

