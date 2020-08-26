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
    window->setVerticalSyncEnabled(true);
    //window->setFramerateLimit(60);
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

    bool Left, Right, Up, Down;
    while (window->isOpen())
    {
        sf::Event event;
        switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Right)
                Right = true;
            else if (event.key.code == sf::Keyboard::Left)
                Left = true;
            else if (event.key.code == sf::Keyboard::Up)
                Up = true;
            else if (event.key.code == sf::Keyboard::Down)
                Down = true;
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Right)
                Right = false;
            else if (event.key.code == sf::Keyboard::Left)
                Left = false;
            else if (event.key.code == sf::Keyboard::Up)
                Up = false;
            else if (event.key.code == sf::Keyboard::Down)
                Down = false;
            break;
        case sf::Event::Closed:
            window->close();
            break;
        default:
            break;
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