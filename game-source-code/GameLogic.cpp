#include "GameLogic.h"

GameLogic::GameLogic(std::shared_ptr<sf::RenderWindow> window):
    pacMan(44.f, 44.f, Vector2(310, 570)),
    Render_(window), window(window)
{
    InitialiseEntities();
}

void  GameLogic::Run()
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
        RenderEntities();
    }
}

void GameLogic::Update()
{
    if (proposed)
    {
        if (Logic.isProsedDirectionMovable(pacMan, ProposedDirection))
        {
            PacManCurrentDirection = ProposedDirection;
            proposed = false;
        }
    }
    Logic.MovePacMan(pacMan, PacManCurrentDirection, 5.f);
    Logic.MoveGhost(Ghosts, 5.f);
    if (IsGameOver_)
    {
        InitialiseEntities();
    }
    if (Logic.PacManAndGhostsCollide(pacMan, Ghosts))
    {
        //GetState() is misspelled
        if (pacMan.GetState() != State::charged)
        {
            pacMan.Die();
            IsGameOver_ = true;
            if (pacMan.GetLifes() == 0) {
                Level = 0;
                pacMan.ResetPoints();
            }
        }
    }
    Logic.EatFruits(pacMan, Fruits);
    if (Logic.AtePallet(pacMan, SuperPallets)) {
        pacMan.SetState(State::SuperCharged);
        Clock_.Reset();
    }
    if (pacMan.GetState() == State::SuperCharged && Clock_.TimeLapse() > 5) {
        pacMan.SetState(State::Alive);
    }
    if (Logic.AtePallet(pacMan, PowerPallets))
    {
        pacMan.SetState(State::charged);
        for (auto i = 0; i < Ghosts.size(); i++) {
            Ghosts[i]->UpdateMode(Mode::Frightened);
        }
        Clock_.Reset();
    }
    if (pacMan.GetState() == State::charged && Clock_.TimeLapse() > 5) {
        pacMan.SetState(State::Alive);
        for (auto i = 0; i < Ghosts.size(); i++) {
            if (Ghosts[i]->GetMode() != Mode::Eaten)
            Ghosts[i]->UpdateMode(Mode::Chase);
        }
    }
    for (auto i = 0; i < Ghosts.size(); i++) {
        if (Ghosts[i]->GetMode() == Mode::Eaten)
            if (Collision::CheckCollision(*Ghosts[i],GhostsHouseDoor))
            {
                Ghosts[i]->UpdateMode(Mode::Chase);
            }
    }
    Logic.OpenDoors(pacMan, Keys, Doors);
    //this will need to go into its on function to improve code self documentation
    if (pacMan.GetState() == State::SuperCharged)
    {
        for (auto door : Doors)
        {
            if (door->IsDoorLocked())
                if (Collision::CheckCollision(*door, pacMan))
                {
                    for (auto key : Keys)
                    {
                        door->Unlock(key);
                    }
                }
        }
    }
    auto MazeWidth = 660;
    Logic.MovablesExitMaze(pacMan, MazeWidth);
    for (auto i = 0; i < Ghosts.size(); i++)
        Logic.MovablesExitMaze(*Ghosts[i], 660);

}

void GameLogic::RenderEntities()
{
    MapEntitiesToModelView();
    Render_.RenderStaticSprites(StaticEntityModelView);
    Render_.RenderGhost(ghostModelView, deltaTime);
    Render_.RenderPacMan(PacManViewModel, deltaTime);
    Render_.RenderText(textModelView);

    if (IsGameOver_)
    {
            GameEndScreen GameEndScr(window);
        //Render_.RenderGameEndScreen(Level, "", false);
        true;
    }
    //Render_.RenderText(textModelView);
    window->display();
    StaticEntityModelView.clear();
    ghostModelView.clear();
}

void GameLogic::MapEntitiesToModelView()
{
    MapEntitiesToDTO::MapPacManViewModel(PacManViewModel, pacMan, PacManCurrentDirection);
    MapTextViewModel();
    MapStaticEntitiesViewModel();
    MapEntitiesToDTO::MapGhostModelView(ghostModelView, Ghosts);
}

// mapping needs to go to it's own class;
void GameLogic::MapTextViewModel()
{
    FileReader filereader_;
    auto hightestScore = filereader_.getHighestScore();
    MapEntitiesToDTO::MapTextViewModel(textModelView, pacMan, hightestScore, (int)Level);

    if (textModelView.currentscore > hightestScore)
    {
        textModelView.HighestScore = to_string(pacMan.GetPoints());
        filereader_.setHighestScore(textModelView.currentscore);
    }
}

void GameLogic::MapStaticEntitiesViewModel()
{
    for (auto door : Doors)
        if (door->IsDoorLocked())
            MapEntitiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, *door);

    MapEntitiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, walls);

    for (auto fruit : Fruits)
        MapEntitiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, fruit);

    for (auto key : Keys)
        MapEntitiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, key);

    for (auto superPallet : SuperPallets)
        MapEntitiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, superPallet);

    for (auto powerPallet : PowerPallets)
        MapEntitiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, powerPallet);

    MapEntitiesToDTO::MapStaticEntitiesModelView(StaticEntityModelView, GhostsHouseDoor);
}


void GameLogic::InitialiseEntities()
{
    if (pacMan.GetLifes() == 3 || pacMan.GetLifes() == 0)
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
    }
    
    IsGameOver_ = false;
    Logic = Application(walls,Doors);

    PacManCurrentDirection = static_cast<Direction>(0);
    ProposedDirection = static_cast<Direction>(0);
    proposed = true;
    auto pacManInitPosition = Vector2(310, 570);
    if(pacMan.GetLifes() == 0)
    pacMan = PacMan(44.f, 44.f, pacManInitPosition);
    pacMan.SetSpeed(2.3);
    pacMan.SetPosition(pacManInitPosition);


    Ghosts.clear();
    Ghosts.push_back(std::make_unique<RedGhost>(TurningPoints, walls, Doors));
    Ghosts.push_back(std::make_unique<PinkGhost>(TurningPoints, walls, Doors, Ghosts[0]->GetPosition_ptr()));
    Ghosts.push_back(std::make_unique<YellowGhost>(TurningPoints, walls, Doors));
    Ghosts.push_back(std::make_unique<BlueGhost>(TurningPoints, walls, Doors));

    for (auto i = 0; i < Ghosts.size(); i++)
    {
        Ghosts[i]->SetPackManPosition(pacMan.GetPosition_ptr());
    }
}


void GameLogic::MovingToTheNextLevel()
{
    if (Fruits.size() == 0) {
        Level++;
        //call end game screen;
        InitialiseEntities();
        //Render_.RenderGameEndScreen(Level,"");
    }
}
