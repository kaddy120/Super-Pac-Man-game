#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Application.h"
#include "Sprite.h"
#include "GameMap.h"
#include <vector>
#include <tuple>
#include "PacMan.h"
#include "Collision.h"
#include "RedGhost.h"

int main()
{
    srand(time(NULL));
    Window Game_Screan;
    std::shared_ptr<sf::RenderWindow> window = Game_Screan.getWindow();
    window->setVerticalSyncEnabled(true);
    //window->setFramerateLimit(60);
    // test -----------------------

    GameMap testMap;
    auto walls = testMap.GetWalls();
    auto TurningPoints = testMap.GetTurningPoinints();
    auto Doors = testMap.GetDoors();
    auto Keys = testMap.GetKeys();
    PacMan player1(35, 35, Vector2(300, 300));
    PacMan player2(35, 35, Vector2(500, 500));
    RedGhost redGhost(TurningPoints, walls, Doors, 3.f, Vector2(320, 300));
    redGhost.SetPackManPosition(player1.GetPosition_ptr());

    sf::RectangleShape rectangle(sf::Vector2f(60.f, 8.f));
    sf::RectangleShape door(sf::Vector2f(60.f, 8.f));
    door.setFillColor(sf::Color(189, 136, 4));

    sf::RectangleShape player1Sprite(sf::Vector2f(35.f, 35.f));
    sf::RectangleShape player2Sprite(sf::Vector2f(35.f, 35.f));
    sf::CircleShape circle_(10.f);
    circle_.setFillColor(sf::Color(89, 250, 150));

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
        
        redGhost.Movement();
        if (Up)
        {
            temp = player1.GetPosition();
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
            temp = player1.GetPosition();
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
            temp = player1.GetPosition();
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
            temp = player1.GetPosition();
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
        for (auto it = Keys.begin(); it!=Keys.end(); it++)
        {
            if (Collision::CheckCollision(*it, player1))
            {
                for (auto Door : Doors)
                {
                    if(Door->HasKey() && Door->IsDoorLocked())
                    Door->Unlock(*it);
                }
                Keys.erase(it);
                break;
            }
        }

        window->clear(sf::Color::Black);


        for (auto wall : walls)
        {
          auto position = wall.GetPosition();
          auto [width, height] = wall.getDimentions();
          rectangle.setSize(sf::Vector2f(width, height));
          rectangle.setPosition(position.X, position.Y);
          window->draw(rectangle);
        }
        for (auto Door : Doors)
        {
            if (Door->IsDoorLocked()) {
            auto position = Door->GetPosition();
            auto [width, height] = Door->getDimentions();
            door.setSize(sf::Vector2f(width, height));
            door.setPosition(position.X, position.Y);
            window->draw(door);
            }
        }
        for (auto Key : Keys)
        {
            auto position = Key.GetPosition();
            auto radius = Key.GetRadius();
            circle_.setPosition(position.X, position.Y);
           // circle_.setOrigin(position.X, position.Y);
            window->draw(circle_);
        }
        player1Sprite.setPosition(player1.GetPosition().X, player1.GetPosition().Y);
        player2Sprite.setPosition(redGhost.GetPosition().X, redGhost.GetPosition().Y);
        window->draw(player1Sprite);
        window->draw(player2Sprite);

        window->display();
    }

    return EXIT_SUCCESS;
}