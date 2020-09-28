#include "Application.h"
#include "GameEndScreen.h"


Application::Application(std::shared_ptr<sf::RenderWindow> window_):
    player1(44.f, 44.f, Vector2(310, 570)),
    window(window_),
    Render_(window_)
{
    InitialiseEntities();
}


void Application::Start()
{
    SplashScreen splashScreen(window);

    sf::Clock clock;
    while (window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        window->clear(sf::Color::Black);
        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Right)
                    ProposedDirection = Direction::Right;
                //Right = true;
                else if (event.key.code == sf::Keyboard::Left)
                    //Left = true;
                    ProposedDirection = Direction::Left;
                else if (event.key.code == sf::Keyboard::Up)
                    //Up = true;
                    ProposedDirection = Direction::Up;
                else if (event.key.code == sf::Keyboard::Down)
                    //Down = true;
                    ProposedDirection = Direction::Down;
                proposed = true;
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
    if (IsGameOver())
    {
        player1.SubtractLife();
        if (player1.GetLifes() == 0)
        {
            Level = 0;
            player1.ResetPoints();
        }
    }
    EatFruits();
    OpenDoors();
    MovingToTheNextLevel();
}

void Application::Render()
{
    MapEntitiesToModelView();
    Render_.RenderStaticSprites(StaticEntityModelView);
    Render_.RenderPacMan(pacManModelVIew, deltaTime);
    Render_.RenderGhost(ghostModelView, deltaTime);
    Render_.RenderText(textModelView);

    if (IsGameOver_)
    {
        Render_.RenderGameEndScreen(Level, "", false);
    }
    //Render_.RenderText(textModelView);

    window->display();
    StaticEntityModelView.clear();
    ghostModelView.clear();
}

void Application::InitialiseEntities()
{
    GameMap GameMap{};
    walls = GameMap.GetWalls();
    TurningPoints = GameMap.GetTurningPoinints();
    Doors = GameMap.GetDoors();
    Keys = GameMap.GetKeys();
    Fruits = GameMap.GetFruits();
    IsGameOver_ = false;

    PacManCurrentDirection = static_cast<Direction>(0);
    ProposedDirection = static_cast<Direction>(0);
    proposed = true;
    player1 = PacMan(44.f, 44.f, Vector2(310, 570));

    Ghosts.clear();
    Ghosts.push_back(std::make_unique<RedGhost>(TurningPoints, walls, Doors));
    Ghosts.push_back(std::make_unique<PinkGhost>(TurningPoints, walls, Doors, Ghosts[0]->GetPosition_ptr()));
    Ghosts.push_back(std::make_unique<YellowGhost>(TurningPoints, walls, Doors));
    Ghosts.push_back(std::make_unique<BlueGhost>(TurningPoints, walls, Doors));

    for (auto i = 0; i < Ghosts.size(); i++)
    {
        Ghosts[i]->SetPackManPosition(player1.GetPosition_ptr());
    }
}
void Application::CheckGameEnd()
{
    //alright, i need end game screen which
}

bool Application::IsGameOver()
{
    for (auto i = 0; i < Ghosts.size(); i++)
    {
        if (Collision::CheckCollision(*Ghosts[i], player1))
        {
            IsGameOver_ = true;
            player1;
            Ghosts[i];
        }
    }
    return IsGameOver_;
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

// if i remove this fucntion i will reduce the line of code by 3 lines
void Application::MoveGhost()
{
    for (auto i = 0; i < Ghosts.size(); i++)
    {
        Ghosts[i]->Move();
    }
}

void Application::MovePacMan()
{
    auto temp = player1.GetPosition();
    auto Unmovable = false;
    auto Unmovable_ = false;
    if (proposed)
    {
        if (isProsedDirectionMovable())
        {
            PacManCurrentDirection = ProposedDirection;
            proposed = false;
        }
    }
    player1.Move(PacManCurrentDirection);
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

bool Application::isProsedDirectionMovable()
{
    Sprite Temp(44,44,player1.GetPosition());
    Movement move_{ 8.f};
    move_.Move(Temp.GetPosition_ptr(), ProposedDirection);
    if(Collision::CheckCollision(Temp, walls)) return false;
    for (auto Door : Doors)
    {
        if (Door->IsDoorLocked())
        {
            if (Collision::CheckCollision(Temp, *Door)) return false;
        }
    }
    return true;
}

void Application::MovablesExitMaize()
{
}

void Application::MovingToTheNextLevel()
{
    if (Fruits.size() == 0) {
        Level++;
        //call end game screen;
        InitialiseEntities();
        Render_.RenderGameEndScreen(Level,"");
    }

}

void CloseGame()
{
    //save score and level to a file
    //and if score is greater than highest score, update highest score
}

void Application::MapEntitiesToModelView()
{
    MapPacManModelView();
    MapTextModelView();
    MapStaticEntitiesModelView();
    MapGhostModelView();
}
// mapping needs to go to it's own class;
void Application::MapTextModelView()
{
    FileReader filereader_;
    textModelView.highscore_=filereader_.getHighestScore();//Reqading the prevously saved highest score


    textModelView.Lives = to_string(player1.GetLifes());
    textModelView.HighestScore = to_string(textModelView.highscore_);

    textModelView.CurrentScore = to_string(player1.GetPoints());
    textModelView.currentscore=player1.GetPoints();

    if(textModelView.currentscore>textModelView.highscore_)//comparing score and highest score
    {
        textModelView.HighestScore=to_string(player1.GetPoints());
        filereader_.setHighestScore(textModelView.currentscore);//Reading into a file the saved highest score

    }

//======================================Lives remaining=======================




    textModelView.Level = "1";


}
void Application::MapPacManModelView() {
    pacManModelVIew.Direction = PacManCurrentDirection;
    pacManModelVIew.Positon = player1.GetPosition();
    auto [width, height] = player1.getDimentions();
    pacManModelVIew.Dimention = Vector2(width, height);
}

void Application::MapGhostModelView()
{
    for (auto i = 0; i < Ghosts.size(); i++)
    {
        GhostModelView tempModel;
        tempModel.Positon = Ghosts[i]->GetPosition();
        tempModel.Dimention = Ghosts[i]->GetPosition();
        tempModel.Mode = Ghosts[i]->GetMode();
        tempModel.Title = Ghosts[i]->Name();
        ghostModelView.push_back(tempModel);
    }
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

    for (auto fruit : Fruits)
    {
        model.Title = "Fruit";
        auto radius = fruit.GetRadius();
        model.Dimention = Vector2(radius*2, radius*2);
        model.Positon = fruit.GetPosition();
        StaticEntityModelView.push_back(model);
    }
    for (auto key : Keys)
    {
        model.Title = "Key";
        auto radius = key.GetRadius();
        model.Dimention = Vector2(radius * 2, radius * 2);
        model.Positon = key.GetPosition();
        StaticEntityModelView.push_back(model);
    }
}
