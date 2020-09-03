#include "Ghost.h"
#include <iostream>

GhostAbstract::GhostAbstract(
	std::vector<CircleSprite> turningTiles,
	std::vector<Sprite> walls,
	const float& radius, 
	const Vector2& initPosition): CircleSprite(radius, initPosition)
{
	TurningTiles = turningTiles;
	Walls = walls;
	StartTime = std::chrono::steady_clock::now();
}

void GhostAbstract::SetPackManPosition(const std::shared_ptr<Vector2>& position)
{
    PacManPostion=position;
}

void GhostAbstract::SetDoorPosition(const Vector2& doorSquar)
{
	Vector2 DoorPostion=doorSquar;
}

void GhostAbstract::UpdateMode(const Mode& mode)
{
	if (mode == Mode::Frightened)
	{
		auto toInt = (int)CurrentDirection;
		//this is to ensure that a randomly selected direction is not a reverse direction;
		if (toInt % 2 == 0) toInt -= 1;
		else
		toInt += 1;
		CurrentDirection = static_cast<Direction>(toInt);
	}
	Mode_ = mode;
}

void GhostAbstract::SetSpeed(const float& speed) 
{
	Speed = speed;
}

//in scared move, ghost will take 180 turn and will randomlys just turn way at any given turnable tiles
void GhostAbstract::ScaredMovement()
{
	    SetPosition(Move(CurrentDirection));

		auto isInside_turningTile = Collision::CheckCollision(*this, TurningTiles);
		if (isInside_turningTile)
		{
			CurrentDirection = RandomDirection();
		}
}

void GhostAbstract::ChaseTargetMovement()
{
	/////////////////////////////////////////////
	//if(isSelectedDirectionMovable(CurrentDirection))
	SetPosition(Move(CurrentDirection));
	auto isInside_turningTile = Collision::CheckCollision(*this, TurningTiles);
	if (isInside_turningTile && count_>=30)
	{
		SetPosition(Move(CurrentDirection));
		//SetPosition(Move(CurrentDirection));
		ChaseTarget();
		count_ = 0;
	}
	count_++;
}

Vector2 GhostAbstract::Move(const Direction& direction)
{
	Vector2 temp;
	switch (direction)
	{
	case Up:
		temp = this->GetPosition();
		temp.subtract(Vector2(0, Speed));	
		break;
	case Down:
		temp = this->GetPosition();
		temp.add(Vector2(0, Speed));
		break;
	case Right:
		temp = this->GetPosition();
		temp.add(Vector2(Speed, 0));
		break;
	case Left:
		temp = this->GetPosition();
		temp.subtract(Vector2(Speed, 0));
		break;
	}
	return temp;
}


void GhostAbstract::ChaseTarget()
{
	auto TryLeftRight = false;
	//auto WrongDirection = false;
	if (abs(GetPosition().Y - Target.Y) > 30)
		if ((Target.Y < GetPosition().Y && CurrentDirection == Down) || (Target.Y > GetPosition().Y && CurrentDirection == Up))
		{
			if (GetPosition().X < Target.X)
			{
				if (isSelectedDirectionMovable(Right))
				{
					CurrentDirection = Right;
					return;
				}
				else
				{
					CurrentDirection = Left;
					return;
				}
			}
			else
			{
				if (isSelectedDirectionMovable(Left))
				{
					CurrentDirection = Left;
					return;
				}
				else
				{
					CurrentDirection = Right;
					return;
				}
			}
		}

	if (abs(GetPosition().Y - Target.Y) > 30)
	{
		if (Target.Y < GetPosition().Y && CurrentDirection != Down)//going up
		{
			if (isSelectedDirectionMovable(Up))
			{
				CurrentDirection = Up;
			}
			else
				TryLeftRight = true;
		}
		if (Target.Y > GetPosition().Y && CurrentDirection != Up)
		{
			if (isSelectedDirectionMovable(Down))
			{
				CurrentDirection = Down;
			}
			else
				TryLeftRight = true;
		}
	}
	if (TryLeftRight || abs(GetPosition().Y - Target.Y) < 30)
	{
		if (GetPosition().X < Target.X)
		{
			if (isSelectedDirectionMovable(Right))
			{
				CurrentDirection = Right;
				TryLeftRight = false;
			}
		}
		else
		{
			if (isSelectedDirectionMovable(Left))
			{
				CurrentDirection = Left;
				TryLeftRight = false;

			}
		}
	}
	if (TryLeftRight)
	{
		CurrentDirection = RandomDirection();
	}
}

Direction GhostAbstract::RandomDirection()
{
	Direction temp;
	auto toInt = static_cast<int>(CurrentDirection);
	//this is to ensure that a randomly selected direction is not a reverse direction;
	if (toInt % 2 == 0) toInt -= 1;
	else
		toInt += 1;
	do {
		do {
			temp = static_cast<Direction>((rand() % 4)+1);

		} while (static_cast<int>(temp) == toInt);
	} while (!isSelectedDirectionMovable(temp));

	return temp;
}

bool GhostAbstract::isSelectedDirectionMovable(const Direction& direction)
{
	Sprite tempSprite(20, 20, Vector2(0,0));
	auto displace_test = 35.f;
	auto isMovable = true;
	auto temp = this->GetPosition();
	switch (direction)
	{
	case Up:
		temp.subtract(Vector2(0, displace_test));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls))
			isMovable = false;
		break;
	case Down:
		temp.add(Vector2(0, displace_test));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls))
			isMovable = false;
		break;
	case Right:
		temp.add(Vector2(displace_test,0));
		tempSprite.SetPosition(temp);
		if(Collision::CheckCollision(tempSprite, Walls))
			isMovable = false;
		break;
	case Left:
		temp.subtract(Vector2(displace_test,0));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls))
			isMovable = false;
		break;
	}
	return isMovable;
}

void GhostAbstract::SetChaseMode()
{
	auto Now = std::chrono::steady_clock::now();
	auto elapsed_seconds = Now - StartTime;
	unsigned int duration = 0;
	if (elapsed_seconds.count() < duration+7)
	{
		Mode_ = Mode::Scatter;
	}
	else if (elapsed_seconds.count() < duration+20)
	{
		Mode_ = Mode::Chase;
	}
	else if (elapsed_seconds.count() < duration+7)
	{
		Mode_ = Mode::Scatter;
	}
	else if (elapsed_seconds.count() < duration+20)
	{
		Mode_ = Mode::Chase;
	}
	else if (elapsed_seconds.count() < duration+5)
	{
		Mode_ = Mode::Scatter;
	}
	else if (elapsed_seconds.count() < duration+20)
	{
		Mode_ = Mode::Chase;
	}else if (elapsed_seconds.count()< duration+5)
	{
		Mode_ = Mode::Scatter;
	}
	else
		Mode_ = Mode::Chase;
}

