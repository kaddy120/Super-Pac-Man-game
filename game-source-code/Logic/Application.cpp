#include "Application.h"

Application::Application(vector<RectangularEntity> walls, vector<std::shared_ptr<Door>> Doors)
{
    this->walls = walls;
    this->Doors = Doors;
}

bool Application::AtePallet(PacMan& pacMan, std::vector<Pellet>& pallets)
{
    for (auto it = pallets.begin(); it != pallets.end(); it++)
    {
        if (Collision::CheckCollision(*it, pacMan))
        {
            pacMan.IncreamentPoints(it->GetPoints());
            pallets.erase(it);
            return true;
        }
    }
    return false;
}

void Application::MovablesExitMaze(IEntity& MovableEntity, const unsigned int& mazeWidth)
{
    auto position = MovableEntity.GetPosition();
    if (position.X < 0)
    {
        position.X = mazeWidth;
        MovableEntity.SetPosition(position);
    }
    else if (position.X > mazeWidth)
    {
        position.X = 0;
        MovableEntity.SetPosition(position);
    }
}


void Application::EatFruits(PacMan& pacMan, std::vector<Fruit>& Fruits)
{
    for (auto it = Fruits.begin(); it != Fruits.end(); it++)
    {
        if (Collision::CheckCollision(*it, pacMan))
        {
            pacMan.IncreamentPoints(it->GetPoints());
            Fruits.erase(it);
            break;
        }
    }
}

void Application::OpenDoors(const PacMan& pacMan, std::vector<Key>& Keys, vector<std::shared_ptr<Door>>& Doors)
{
    for (auto it = Keys.begin(); it != Keys.end(); it++)
    {
        if (Collision::CheckCollision(*it, pacMan))
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
void Application::MoveGhost(std::vector<std::unique_ptr<AbstractGhost>>& Ghosts, const float& deltaTime)
{
    for (auto i = 0; i < Ghosts.size(); i++)
    {
        Ghosts[i]->Move();
    }
}

bool Application::PacManAndGhostsCollide(const PacMan& pacMan, vector<std::unique_ptr<AbstractGhost>>& Ghosts)
{
    if (pacMan.GetState() == State::SuperCharged) return false;
    for (auto i = 0; i < Ghosts.size(); i++)
    {
        if (Collision::CheckCollision(*Ghosts[i], pacMan))
        {
            if (pacMan.GetState() == State::charged) Ghosts[i]->UpdateMode(Mode::Eaten);
            return true;
        }
    }
    return false;
}

void Application::MovePacMan(PacMan& pacMan, const Direction& direction, const float& deltaTime)
{
    auto temp = pacMan.GetPosition();
    auto Unmovable = false;
    auto Unmovable_ = false;

    pacMan.Move(direction);
    for (auto wall : walls)
    {
        Unmovable = Collision::CheckCollision(pacMan, wall);
        if (Unmovable)
            break;
    }
    if(pacMan.GetState()!=State::SuperCharged)
    for (auto Door : Doors)
    {
        if (Door->IsDoorLocked())
        {
            if (Collision::CheckCollision(pacMan, *Door))
            {
                Unmovable = true;
                break;
            }
        }
    }
    if (Unmovable_ || Unmovable)
        pacMan.SetPosition(temp);
}

bool Application::isProsedDirectionMovable(
    const PacMan& pacMan,
    const Direction& direction)
{
    auto [width, height] = pacMan.getDimentions();
    RectangularEntity Temp(width,height, pacMan.GetPosition());
    Movement move_{ 8.f};
    move_.Move(Temp.GetPosition_ptr(), direction);
    if(Collision::CheckCollision(Temp, walls)) return false;
    
    if(pacMan.GetState()!= State::SuperCharged)
    for (auto Door : Doors)
    {
        if (Door->IsDoorLocked())
        {
            if (Collision::CheckCollision(Temp, *Door)) return false;
        }
    }
    return true;
}


void CloseGame()
{
    //save score and level to a file
    //and if score is greater than highest score, update highest score
}


