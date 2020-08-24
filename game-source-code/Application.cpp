#include "Application.h"


void Application::Start() const
{
    sf::RenderWindow Game_Screen(sf::VideoMode(800, 600, 32), 
        "Duel Invaders", sf::Style::Titlebar | sf::Style::Close);

    while (Game_Screen.isOpen()) 
    {
        sf::Event event;
        while (Game_Screen.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                Game_Screen.close();
        }
    }
}