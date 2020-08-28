#include "Ghost.h"

GhostAbstract::GhostAbstract(
	std::vector<Sprite> turningTiles,
	std::vector<Sprite> walls,
	const float& width, 
	const float& height,
	const Vector2& initPosition): Sprite(width, height, initPosition)
{
	TurningTiles = turningTiles;
	Walls = walls;
	StartTime = std::chrono::steady_clock::now();
}

void GhostAbstract::SetPackManPosition(std::shared_ptr<Vector2>& position)
{
    PacManPostion=position;
}

void GhostAbstract::SetDoorPosition(const Vector2& doorSquar)
{
	Vector2 DoorPostion=doorSquar;
}

void GhostAbstract::UpdateMode(const Mode& mode)
{
	if (mode == Mode::Scared)
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
	    this->SetPosition(Move(CurrentDirection));

		auto isInside_turningTile=Collision().CheckCollision(*this, TurningTiles);
		if (isInside_turningTile)
		{
			CurrentDirection = RandomDirection();
		}
}

void GhostAbstract::ChaseTarget()
{
	auto TryLeftRight = false;
	if (abs(GetPostion().Y - Target.Y) > 30)
	{
		if (GetPostion().Y < Target.Y && CurrentDirection != Down)//going up
		{
			if (isSelectedDirectionMovable(Up))
			{
				CurrentDirection = Up;
			}
			else
				TryLeftRight = true;
		}
		else if (CurrentDirection != Up)
		{
			if (isSelectedDirectionMovable(Up))
			{
				CurrentDirection = Down;
			}
			else
				TryLeftRight = true;
		}
	}
	else if (TryLeftRight || abs(GetPostion().Y - Target.Y) < 30)
	{
		if (GetPostion().X < Target.X)
		{
			if (isSelectedDirectionMovable(Left))
			{
				CurrentDirection = Left;
				TryLeftRight = false;

			}
		}
		else
		{
			if (isSelectedDirectionMovable(Down))
			{
				CurrentDirection = Down;
				TryLeftRight = false;
			}
		}
	}
	if (TryLeftRight)
	{
		CurrentDirection = RandomDirection();
	}
}


Vector2 GhostAbstract::Move(const Direction& direction)
{
	Vector2 temp;
	switch (direction)
	{
	case Up:
		temp = this->GetPostion();
		temp.subtract(Vector2(0, Speed));	
	case Down:
		temp = this->GetPostion();
		temp.add(Vector2(0, Speed));
	case Right:
		temp = this->GetPostion();
		temp.add(Vector2(Speed, 0));
	case Left:
		temp = this->GetPostion();
		temp.subtract(Vector2(Speed, 0));
	}
	return temp;
}

Direction GhostAbstract::RandomDirection()
{
	Direction temp;
	auto toInt = (int)CurrentDirection;
	//this is to ensure that a randomly selected direction is not a reverse direction;
	if (toInt % 2 == 0) toInt -= 1;
	else
		toInt += 1;
	do {
		do {
			temp = static_cast<Direction>(rand() % 4);

		} while ((int)temp == toInt);
	} while (!isSelectedDirectionMovable(temp));

	return temp;
}

bool GhostAbstract::isSelectedDirectionMovable(const Direction& direction)
{
	Sprite tempSprite(40, 40, Vector2(0,0));
	auto displace_test = 8.f;
	auto isMovable = true;
	switch (direction)
	{
	case Up:
		auto temp = this->GetPostion();
		temp.subtract(Vector2(0, displace_test));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls))
			isMovable = false;
	case Down:
		auto temp = this->GetPostion();
		temp.add(Vector2(0, displace_test));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls))
			isMovable = false;
	case Right:
		auto temp = this->GetPostion();
		temp.add(Vector2(displace_test,0));
		tempSprite.SetPosition(temp);
		if(Collision::CheckCollision(tempSprite, Walls))
			isMovable = false;
	case Left:
		auto temp = this->GetPostion();
		temp.subtract(Vector2(displace_test,0));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls))
			isMovable = false;
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
		Mode_ = Mode::Frightened;
	}
	else if (elapsed_seconds.count() < duration+20)
	{
		Mode_ = Mode::Chase;
	}
	else if (elapsed_seconds.count() < duration+7)
	{
		Mode_ = Mode::Frightened;
	}
	else if (elapsed_seconds.count() < duration+20)
	{
		Mode_ = Mode::Chase;
	}
	else if (elapsed_seconds.count() < duration+5)
	{
		Mode_ = Mode::Frightened;
	}
	else if (elapsed_seconds.count() < duration+20)
	{
		Mode_ = Mode::Chase;
	}else if (elapsed_seconds.count()< duration+5)
	{
		Mode_ = Mode::Frightened;
	}
	else
		Mode_ = Mode::Chase;
}

