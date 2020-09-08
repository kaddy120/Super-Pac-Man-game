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
#include "SplashScreen.h"
#include "PinkGhost.h"
#include "YellowGhost.h"

int main()
{
    srand(time(NULL));
    Window Game_Screan;
    std::shared_ptr<sf::RenderWindow> window = Game_Screan.getWindow();
    window->setVerticalSyncEnabled(true);

    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"));
    { 
        std::cout << "Failed to load a font" << std::endl;
    }
    sf::Text Score;
    Score.setFont(font);
    Score.setCharacterSize(30);
    Score.setPosition(20.f, 18.f);
    Score.setFillColor(sf::Color::White);
    
    //window->setFramerateLimit(60);
    // test -----------------------

    GameMap testMap;
    auto walls = testMap.GetWalls();
    auto TurningPoints = testMap.GetTurningPoinints();
    auto Doors = testMap.GetDoors();
    auto Keys = testMap.GetKeys();
    auto Fruits = testMap.GetFruits();
    PacMan player1(32.f, 32.f, Vector2(310, 500));
    PacMan player2(35, 35, Vector2(500, 500));
    RedGhost redGhost(TurningPoints, walls, Doors, 3.f, Vector2(320, 300));
    PinkGhost pinkGhost(TurningPoints, walls, Doors, 3.f, Vector2(320, 300));
    YellowGhost yellowGhost(TurningPoints, walls, Doors, 3.f, Vector2(320, 300));
    pinkGhost.SetPackManPosition(player1.GetPosition_ptr());
    pinkGhost.SetRedGhostPosition(redGhost.GetPosition_ptr());
    yellowGhost.SetPackManPosition(player1.GetPosition_ptr());
    redGhost.SetPackManPosition(player1.GetPosition_ptr());

    sf::RectangleShape rectangle(sf::Vector2f(60.f, 8.f));
    sf::RectangleShape door(sf::Vector2f(60.f, 8.f));
    door.setFillColor(sf::Color(189, 136, 4));

    sf::RectangleShape player1Sprite(sf::Vector2f(35.f, 35.f));
    player1Sprite.setFillColor(sf::Color(230, 207, 5));
    sf::RectangleShape player2Sprite(sf::Vector2f(35.f, 35.f));
    sf::CircleShape circle_(10.f);
    sf::CircleShape fruit_(10.f);
    circle_.setFillColor(sf::Color(89, 250, 150));
    fruit_.setFillColor(sf::Color(193, 237, 36));

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
    //bool Left = false, Right = false, Up = false, Down = false;

    SplashScreen splashScreen(window);

    Move PacManCurrentDirection;
    PacManCurrentDirection = Move::NotMoving;

    while (window->isOpen())
    {
        window->clear(sf::Color::Black);
        sf::Event event;
        while (window->pollEvent(event)) {

            switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Right)
                    PacManCurrentDirection = Move::Right;
                //Right = true;
                else if (event.key.code == sf::Keyboard::Left)
                    //Left = true;
                    PacManCurrentDirection = Move::Left;
                else if (event.key.code == sf::Keyboard::Up)
                    //Up = true;
                    PacManCurrentDirection = Move::Up;
                else if (event.key.code == sf::Keyboard::Down)
                    //Down = true;
                    PacManCurrentDirection = Move::Down;
                break;
            case sf::Event::Closed:
                window->close();
                break;
            default:
                break;
            }
        }
        
        redGhost.Movement();
        pinkGhost.Movement();
        yellowGhost.Movement();
        ////pacMan movement/////////////////
        auto temp = player1.GetPosition();
        player1.Movement(PacManCurrentDirection);
        auto Unmovable = false;
        auto Unmovable_ = false;
        for (auto wall : walls)
        {
            Unmovable = Collision::CheckCollision(player1, wall);
            if (Unmovable)
                break;
        }
        for (auto Door : Doors)
        {
            if (Door->IsDoorLocked())
            {
                if (Collision::CheckCollision(player1, *Door))
                {
                    Unmovable = true;
                    break;
                }
            }
        }
        if (Unmovable_ || Unmovable)
            player1.SetPosition(temp);
        //------------------------------------------------------

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

        for (auto it = Fruits.begin(); it != Fruits.end(); it++)
        {
            if (Collision::CheckCollision(*it, player1))
            {
                player1.IncreamentPoints(it->FruitPoints());
                Fruits.erase(it);
                break;
            }
        }
        
        auto Score_str = to_string(player1.GetPoints());

        Score.setString("Score: "+ Score_str);
        window->draw(Score);
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
            window->draw(circle_);
        }
        for (auto Fruit : Fruits)
        {
            auto position = Fruit.GetPosition();
            fruit_.setRadius(Fruit.GetRadius());
            fruit_.setPosition(position.X, position.Y);
            window->draw(fruit_);
        }
        player1Sprite.setPosition(player1.GetPosition().X, player1.GetPosition().Y);
        window->draw(player1Sprite);
        player2Sprite.setPosition(redGhost.GetPosition().X, redGhost.GetPosition().Y);
        window->draw(player2Sprite);
        player2Sprite.setPosition(pinkGhost.GetPosition().X, pinkGhost.GetPosition().Y);
        window->draw(player2Sprite);
        player2Sprite.setPosition(yellowGhost.GetPosition().X, yellowGhost.GetPosition().Y);
        window->draw(player2Sprite);

        window->display();
    }

    return EXIT_SUCCESS;
}