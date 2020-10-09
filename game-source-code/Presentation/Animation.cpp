#include "Animation.h"

Animation::Animation(sf::Texture* texture, const sf::Vector2u& imageCount, const float& switchTime)
{
	SwitchTime = switchTime;
	ImageCount = imageCount;
	TotalTime = 0;
	CurrentImage.x = 0;
	uvRect.height = texture->getSize().y / ImageCount.y;
	uvRect.width = texture->getSize().x / ImageCount.x;
}

void Animation::Update(const unsigned int& row, const float& deltaTime)
{
	CurrentImage.y = row;
	TotalTime += deltaTime;
	if (TotalTime >= SwitchTime)
	{
		TotalTime -= SwitchTime;
		CurrentImage.x++;
		if (CurrentImage.x >= ImageCount.x)
		{
			CurrentImage.x = 0;
		}
	}

	uvRect.top = uvRect.height * CurrentImage.y;
	uvRect.left = uvRect.width * CurrentImage.x;
}

sf::IntRect Animation::GetIntRect()
{
	return uvRect;
}
