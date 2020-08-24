#pragma once
#include <SFML/Graphics.hpp>

class Input
{
public:
    Input(std::shared_ptr<sf::RenderWindow>& window) {

        while (window->pollEvent(event)) {

            switch (event.type) {
            case sf::Event::KeyPressed:
                //if (event.key.code == sf::Keyboard::Right)
                //    //moving_right = true;
                //    return;
                //else if (event.key.code == sf::Keyboard::Left)
                //    // = true;
                //    return;
                //else if (event.key.code == sf::Keyboard::Z)
                //    //moving_left_ = true;
                //    return;
                //else if (event.key.code == sf::Keyboard::C)
                //    //moving_right_ = true;
                //    return;
                //break;
            case sf::Event::KeyReleased:
                //if (event.key.code == sf::Keyboard::Right)
                //    //moving_right = false;
                //    return;
                //else if (event.key.code == sf::Keyboard::Left)
                //    /* moving_left = false;*/
                //    return;
                //else if (event.key.code == sf::Keyboard::Z)
                //    //moving_left_ = false;
                //    return;
                //else if (event.key.code == sf::Keyboard::C)
                //    //moving_right_ = false;
                //    return;
                //else if (event.key.code == sf::Keyboard::Down)
                //    //shooting_down = true;
                //    return;
                //else if (event.key.code == sf::Keyboard::Space)
                //    //shooting_up = true;
                //    return;
                //break;
            case sf::Event::Closed:
                window->close();
                break;
            default:
                break;
            }

        }
    }

private:
    sf::Event event;
    bool MovingRight = false;
    bool MovingLeft = false;
    bool MovingUp = false;
    bool MovingDown = false;
};
