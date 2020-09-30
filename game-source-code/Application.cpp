#include "Application.h"

Application::Application(vector<Sprite> walls, vector<std::shared_ptr<Door>> Doors)
{
    this->walls = walls;
    this->Doors = Doors;
}

bool Application::AtePallet(PacMan& pacMan, std::vector<SuperPallet>& pallets)
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


void Application::EatFruits(PacMan& pacMan, std::vector<Fruit>& Fruits)
{
    for (auto it = Fruits.begin(); it != Fruits.end(); it++)
    {
        if (Collision::CheckCollision(*it, pacMan))
        {
            pacMan.IncreamentPoints(it->FruitPoints());
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
    if (pacMan.GetSate() == State::SuperCharged) return false;
    for (auto i = 0; i < Ghosts.size(); i++)
    {
        if (Collision::CheckCollision(*Ghosts[i], pacMan))
        {
            if (pacMan.GetSate() == State::charged) Ghosts[i]->UpdateMode(Mode::Eaten);
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
    if(pacMan.GetSate()!=State::SuperCharged)
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
    Sprite Temp(width,height, pacMan.GetPosition());
    Movement move_{ 8.f};
    move_.Move(Temp.GetPosition_ptr(), direction);
    if(Collision::CheckCollision(Temp, walls)) return false;
    
    if(pacMan.GetSate()!= State::SuperCharged)
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


