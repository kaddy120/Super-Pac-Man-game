#pragma once
#include <SFML/Graphics.hpp>

class Input
{
public:
    Input(std::shared_ptr<sf::RenderWindow>& window_)
    {
        window = window_;
    }
    void HandleEvent();

private:
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event event;
    bool MovingRight = false;
    bool MovingLeft = false;
    bool MovingUp = false;
    bool MovingDown = false;
};
