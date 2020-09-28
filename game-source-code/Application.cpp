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
    if (IsGameOver_)
    {
        InitialiseEntities();
    }
//rename this function to PacManAndGhostsCollides()
    if (IsGameOver())
    {
        //GetState() is misspelled
        if (player1.GetSate() != State::charged)
        {
            player1.SubtractLife();
            IsGameOver_ = true;
            if (player1.GetLifes() == 0){
                Level = 0;
                player1.ResetPoints();
            }
        }
        else
        {
            for (auto i = 0; i < Ghosts.size(); i++) {
                Ghosts[i]->UpdateMode(Mode::Eaten);
            }
        }
    }
    EatFruits();
    if (AteSuperPallet()){
        player1.SetState(State::SuperCharged);
        Clock_.Reset();
    }
    if (player1.GetSate() == State::SuperCharged && Clock_.TimeLapse() > 7) {
        player1.SetState(State::Alive);
    }

    if (AtePowerPallet())
    {
        player1.SetState(State::charged);
        for (auto i = 0; i < Ghosts.size(); i++){
            Ghosts[i]->UpdateMode(Mode::Frightened);
        }
        Clock_.Reset();
    }
    if (player1.GetSate() == State::charged && Clock_.TimeLapse() > 20) {
        player1.SetState(State::Alive);
        for (auto i = 0; i < Ghosts.size(); i++) {
            Ghosts[i]->UpdateMode(Mode::Chase);
        }
    }
    OpenDoors();
    //this will need to go into its on function to improve code self documentation
    if (player1.GetSate() == State::SuperCharged)
    {
        for (auto door : Doors)
        {
            if (door->IsDoorLocked())
                if (Collision::CheckCollision(*door, player1))
                {
                    for (auto key : Keys)
                    {
                        door->Unlock(key);
                    }
                }
        }
    }
    MovingToTheNextLevel();
}

void Application::Render()
{
    MapEntitiesToModelView();
    Render_.RenderStaticSprites(StaticEntityModelView);
    Render_.RenderGhost(ghostModelView, deltaTime);
    Render_.RenderPacMan(pacManModelVIew, deltaTime);
    Render_.RenderText(textModelView);

    if (IsGameOver_)
    {
        Render_.RenderGameEndScreen(Level, "", false);
        true;
    }
    //Render_.RenderText(textModelView);

    window->display();
    StaticEntityModelView.clear();
    ghostModelView.clear();
}

void Application::CheckGameEnd()
{
    //alright, i need end game screen which
}

bool Application::IsGameOver()
{
    if (player1.GetSate() == State::SuperCharged) return false;
    for (auto i = 0; i < Ghosts.size(); i++)
    {
        if (Collision::CheckCollision(*Ghosts[i], player1))
        {
            player1;
            Ghosts[i];
            return true;
        }
    }
    return false;
}

//maybe i should rename this to something more general
//superPallet and packMan Can be handled by the same function..
bool Application::AteSuperPallet()
{
    for (auto it = SuperPallets.begin(); it != SuperPallets.end(); it++)
    {
        if (Collision::CheckCollision(*it, player1))
        {
            SuperPallets.erase(it);
            return true;
        }
    }
    return false;
}
//this is temporary
bool Application::AtePowerPallet()
{
    for (auto it = PowerPallets.begin(); it != PowerPallets.end(); it++)
    {
        if (Collision::CheckCollision(*it, player1))
        {
            PowerPallets.erase(it);
            return true;
        }
    }
    return false;
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
    if(player1.GetSate()!=State::SuperCharged)
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
    
    if(player1.GetSate()!= State::SuperCharged)
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
    MapEntiesToDTO::MapPacManModelView(pacManModelVIew, player1, PacManCurrentDirection);
    MapTextModelView();
    MapStaticEntitiesModelView();
    MapEntiesToDTO::MapGhostModelView(ghostModelView, Ghosts);
}
// mapping needs to go to it's own class;
void Application::MapTextModelView()
{
    FileReader filereader_;
    auto hightestScore = filereader_.getHighestScore();
    MapEntiesToDTO::MapTextModelView(textModelView, player1, hightestScore, (int)Level);

    if(textModelView.currentscore> hightestScore)
    {
        textModelView.HighestScore=to_string(player1.GetPoints());
        filereader_.setHighestScore(textModelView.currentscore);
    }
}

void Application::MapStaticEntitiesModelView()
{
    for (auto door : Doors)
        if (door->IsDoorLocked()) 
            MapEntiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, *door);

    MapEntiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, walls);

    for(auto fruit: Fruits)
    MapEntiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView,fruit);

    for (auto key : Keys)
        MapEntiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, key);
    
    for (auto superPallet : SuperPallets)
        MapEntiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, superPallet);

    for (auto powerPallet : PowerPallets)
        MapEntiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, powerPallet);

    MapEntiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView,GhostsHouseDoor);
}

void Application::InitialiseEntities()
{
    GameMap GameMap{};
    walls = GameMap.GetWalls();
    TurningPoints = GameMap.GetTurningPoinints();
    Doors = GameMap.GetDoors();
    GhostsHouseDoor = GameMap.GhostsHouseDoor();
    Keys = GameMap.GetKeys();
    Fruits = GameMap.GetFruits();
    SuperPallets = GameMap.GetSuperPallets();
    PowerPallets = GameMap.GetPowerPallets();
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
