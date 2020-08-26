#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Application.h"
#include "Sprite.h"
#include "GameMap.h"
#include <vector>
#include <tuple>
#include "PacMan.h"
#include "Collision.h"

int main()
{
    Window Game_Screan;
    std::shared_ptr<sf::RenderWindow> window = Game_Screan.getWindow();
    window->setVerticalSyncEnabled(true);
    //window->setFramerateLimit(60);
    // test -----------------------

    GameMap testMap;
    auto walls = testMap.GetWalls();
    PacMan player1(35, 35, Vector2(300, 300));
    PacMan player2(35, 35, Vector2(500, 500));

    sf::RectangleShape rectangle(sf::Vector2f(60.f, 8.f));
    sf::RectangleShape player1Sprite(sf::Vector2f(35.f, 35.f));
    sf::RectangleShape player2Sprite(sf::Vector2f(35.f, 35.f));

    Vector2 position(0, 0);
    Vector2 VerticalIncremet(80.0f, 0.0f);
    Vector2 HorizontalIncrement(0, 80);
    float width_ = 80;
    float height_ = 10;
    float width = 10;
    float height = 80;
    Vector2 temp;
    Sprite Wall_h(width_, height_, position);
    // end ------------------------

    bool Left = false, Right = false, Up = false, Down = false;
    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event)) {

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
        }
        
        if (Up)
        {
            temp = player1.GetPostion();
            player1.MoveUp();
            auto Unmovable = false;
            for (auto wall : walls)
            {
                Unmovable = Collision().CheckCollision(wall, player1);
                if (Unmovable)
                    break;
            }
            if (Unmovable)
                player1.SetPosition(temp);

            
        }
        if (Down)
        {
            temp = player1.GetPostion();
            player1.MoveDown();
            auto Unmovable = false;
            for (auto wall : walls)
            {
                Unmovable = Collision().CheckCollision(wall, player1);
                if (Unmovable)
                    break;
            }
            if (Unmovable)
                player1.SetPosition(temp);
        }
        if (Left)
        {
            temp = player1.GetPostion();
            player1.MoveLeft();
            auto Unmovable = false;
            for (auto wall : walls)
            {
                Unmovable = Collision().CheckCollision(wall, player1);
                if (Unmovable)
                    break;
            }
            if (Unmovable)
                player1.SetPosition(temp);
        }
        if (Right)
        {
            temp = player1.GetPostion();
            player1.MoveRight();
            auto Unmovable = false;
            for (auto wall : walls)
            {
                Unmovable = Collision().CheckCollision(wall, player1);
                if (Unmovable)
                    break;
            }
            if (Unmovable)
                player1.SetPosition(temp);
        }
        window->clear(sf::Color::Black);
        //draw here for testing

     
        // change the size to 100x100

        for (auto wall : walls)
        {
          auto position = wall.GetPostion();
          auto [width, height] = wall.getDimentions();
          rectangle.setSize(sf::Vector2f(width, height));
          rectangle.setPosition(position.X, position.Y);
          window->draw(rectangle);
        }
        player1Sprite.setPosition(player1.GetPostion().X, player1.GetPostion().Y);
        player2Sprite.setPosition(player2.GetPostion().X, player2.GetPostion().Y);
        window->draw(player1Sprite);
        window->draw(player2Sprite);

        window->display();
    }

    return EXIT_SUCCESS;
}