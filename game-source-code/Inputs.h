#pragma once
#include <SFML/Graphics.hpp>

class Input
{
public:
    Input(std::shared_ptr<sf::RenderWindow>& window_)
    {
        //window = window_;
    }
    void HandleEvent();

private:
    //std::unique_ptr<Direction>
};
