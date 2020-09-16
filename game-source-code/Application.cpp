#include "Application.h"

Application::Application(std::shared_ptr<sf::RenderWindow> window_):
    player1(32.f, 32.f, Vector2(310, 500)),
    yellowGhost(TurningPoints, walls, Doors),
    redGhost(TurningPoints, walls, Doors),
    pinkGhost(TurningPoints, walls, Doors),
    window(window_),
    Render_(window_)
{
    InitialiseEntities();
}
    
void Application::Start()
{
    SplashScreen splashScreen(window);

    while (window->isOpen())
    {
        window->clear(sf::Color::Black);
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Right)
                    PacManCurrentDirection = Direction::Right;
                //Right = true;
                else if (event.key.code == sf::Keyboard::Left)
                    //Left = true;
                    PacManCurrentDirection = Direction::Left;
                else if (event.key.code == sf::Keyboard::Up)
                    //Up = true;
                    PacManCurrentDirection = Direction::Up;
                else if (event.key.code == sf::Keyboard::Down)
                    //Down = true;
                    PacManCurrentDirection = Direction::Down;
                break;
            case sf::Event::Closed:
                window->close();
                break;
            default:
                break;
            }
        }
        Update();
        Render();
    }
}

void Application::Update()
{
    MovePacMan();
    MoveGhost();
    EatFruits();
    OpenDoors();
    //isGameOver();
}

void Application::Render()
{
    MapEntitiesToModelView();
    //Render_.RenderPacMan(pacManModelVIew);
    Render_.RenderStaticSprites(StaticEntityModelView);
    //Render_.RenderText(textModelView);
    window->display();
    StaticEntityModelView.clear();
}

void Application::InitialiseEntities()
{
    GameMap GameMap{};
    walls = GameMap.GetWalls();
    TurningPoints = GameMap.GetTurningPoinints();
    Doors = GameMap.GetDoors();
    Keys = GameMap.GetKeys();
    Fruits = GameMap.GetFruits();

    pinkGhost.SetPackManPosition(player1.GetPosition_ptr());
    pinkGhost.SetRedGhostPosition(redGhost.GetPosition_ptr());
    yellowGhost.SetPackManPosition(player1.GetPosition_ptr());
    redGhost.SetPackManPosition(player1.GetPosition_ptr());
}
void Application::CheckGameEnd()
{
}

bool Application::IsGameOver()
{
    // here i have violated dry prinple
    if (Collision::CheckCollision(redGhost, player1)) return true;
    if (Collision::CheckCollision(yellowGhost, player1)) return true;
    if (Collision::CheckCollision(pinkGhost, player1)) return true;
    return false;
}

void Application::InputHandler(const sf::Event& event)
{
    switch (event.type) {
    case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::Right)
            PacManCurrentDirection = Direction::Right;
        //Right = true;
        else if (event.key.code == sf::Keyboard::Left)
            //Left = true;
            PacManCurrentDirection = Direction::Left;
        else if (event.key.code == sf::Keyboard::Up)
            //Up = true;
            PacManCurrentDirection = Direction::Up;
        else if (event.key.code == sf::Keyboard::Down)
            //Down = true;
            PacManCurrentDirection = Direction::Down;
        break;
    case sf::Event::Closed:
        window->close();
        break;
    default:
        break;
    }
}

void Application::EatFruits()
{
    for (auto it = Fruits.begin(); it != Fruits.end(); it++)
    {
        if (Collision::CheckCollision(*it, player1))
        {
            player1.IncreamentPoints(it->FruitPoints());
            Fruits.erase(it);
            break;
        }
    }
}

void Application::OpenDoors()
{
    for (auto it = Keys.begin(); it != Keys.end(); it++)
    {
        if (Collision::CheckCollision(*it, player1))
        {
            for (auto Door : Doors)
            {
                if (Door->HasKey() && Door->IsDoorLocked())
                    Door->Unlock(*it);
            }
            Keys.erase(it);
            break;
        }
    }
}

void Application::MoveGhost()
{
    redGhost.Move();
    yellowGhost.Move();
    pinkGhost.Move();
}

void Application::MovePacMan()
{
    auto temp = player1.GetPosition();
    player1.Move(PacManCurrentDirection);
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
}

void Application::MovablesExitMaize()
{
}

bool Application::MovingToTheNextLevel() 
{
    return false;
}

void Application::MapEntitiesToModelView()
{
    MapPacManModelView();
    MapTextModelView();
    MapStaticEntitiesModelView();
    MapGhostModelView();   
}

void Application::MapTextModelView()
{
    textModelView.Lifes = to_string(player1.GetLifes());
    textModelView.HighestScore = "None";
    textModelView.Level = "1";
    textModelView.CurrentScore = to_string(player1.GetPoints());
}
void Application::MapPacManModelView() {
    pacManModelVIew.Direction = PacManCurrentDirection;
    pacManModelVIew.Positon = player1.GetPosition();
    auto [width, height] = player1.getDimentions();
    pacManModelVIew.Dimention = Vector2(width, height);
}

void Application::MapGhostModelView()
{
    //i need to fix ghost first or i'll repeate Myself
}
void Application::MapStaticEntitiesModelView()
{
    SpriteModelView model;
    for (auto door : Doors)
    {
        if (door->IsDoorLocked())
        {
            model.Title = "Door";
            auto [width, height] = door->getDimentions();
            model.Dimention = Vector2(width, height);
            model.Positon = door->GetPosition();
            StaticEntityModelView.push_back(model);
        }
    }

    for (auto wall : walls)
    {
        model.Title = "Wall";
        auto [width, height] = wall.getDimentions();
        model.Dimention = Vector2(width, height);
        model.Positon = wall.GetPosition();
        StaticEntityModelView.push_back(model);
    }
}
