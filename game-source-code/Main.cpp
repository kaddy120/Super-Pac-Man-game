#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Application.h"
#include "Sprite.h"
#include "GameMap.h"
#include <vector>
#include <tuple>

int main()
{
    Window Game_Screan;
    std::shared_ptr<sf::RenderWindow> window = Game_Screan.getWindow();

    // test -----------------------

    GameMap testMap;
    auto walls = testMap.GetWalls();

    Vector2 position(0, 0);
    Vector2 VerticalIncremet(80.0f, 0.0f);
    Vector2 HorizontalIncrement(0, 80);
    float width_ = 80;
    float height_ = 10;
    float width = 10;
    float height = 80;
    Sprite Wall_h(width_, height_, position);
    // end ------------------------

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window->close();
           
        }
        window->clear(sf::Color::Black);
        //draw here for testing

        sf::RectangleShape rectangle(sf::Vector2f(60.f, 8.f));
        // change the size to 100x100

        for (auto wall : walls)
        {
          auto position = wall.GetPostion();
          auto [width, height] = wall.getDimentions();
          rectangle.setSize(sf::Vector2f(width, height));
          rectangle.setPosition(position.X, position.Y);
          window->draw(rectangle);
        }
        
        window->display();
    }

    return EXIT_SUCCESS;
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