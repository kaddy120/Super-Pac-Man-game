#pragma once
#include <SFML/Graphics.hpp>
/**
 *@class Animation
 *@author Dembe Munyai and Kaddy Marindi
 *@brief This class is used to animate sprite action.
 \version 3.0
*/
class Animation
{
public:
/**
    * @brief This is a default constructor, creating an object of animation
    * @
    *  @return void
    */
	Animation() {}
	/**
    * @brief Parametarised constructer to create an object of animation
    * @param texture is of type sf::Texture*. texture is the sprite image that is animated.
    * @param imageCount is of type sf::Vector2u. this contain number of images in a sprite counting horizontaly and verticaly.
    x is horizontal and y is vertical number of images.
    * @param swithcTime is of type float. This is a duration it takes to switch from one animation image to the next
    */
	Animation(sf::Texture* texture, const sf::Vector2u& imageCount, const float& switchTime);
	/**
    * @brief This function is responsible for updating the animation and selecting which row should be animated
    * @param row is of tpe uint. row start from 0, where if row is 0 the first row of images are inimated.
    row selects an animation row action.
    * @param delataTime is of type float. This is change in time
    *  @return void
    */
	void Update(const unsigned int& row, const float& deltaTime);
	/**
    * @brief this function return an object used to crop an image in a sf::texture that should be displayed
    *  @return return an sf::IntRect Object
    */
	sf::IntRect GetIntRect();
private:
	sf::Vector2u ImageCount;
	sf::Vector2u CurrentImage;
	float TotalTime;
	float SwitchTime;
	sf::IntRect uvRect;
};

