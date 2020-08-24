#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Application.h"

int main()
{
    Window Game_Screan;
    std::shared_ptr<sf::RenderWindow> window = Game_Screan.getWindow();
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }
    /*Application NewGame;
    NewGame.Start();*/
  /*  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;*/
}