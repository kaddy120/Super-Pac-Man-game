#include "GhostNavigator.h"

GhostNavigator::GhostNavigator(
	std::vector<CircleSprite> turningTiles,
	std::vector<Sprite> walls,
	std::vector<std::shared_ptr<Door>> doors,
	std::shared_ptr<Vector2> ghostPosition_ptr) {

	TurningTiles = turningTiles;
	Walls = walls;
	Doors = doors;
	GhostPosition_ptr = ghostPosition_ptr;
}

void GhostNavigator::FindDirectionToTarget()
{
	auto TryLeftRight = false;
	if (abs(GhostPosition_ptr->Y - Target.Y) > 30)
		if ((Target.Y < GhostPosition_ptr->Y && CurrentDirection == Down) || (Target.Y > GhostPosition_ptr->Y && CurrentDirection == Up))
		{
			if (GhostPosition_ptr->X < Target.X)
			{
				if (isSelectedDirectionMovable(Right) && CurrentDirection != Left)
				{
					CurrentDirection = Right;
					return;
				}
				else if(isSelectedDirectionMovable(Left) && CurrentDirection != Right)
				{
					CurrentDirection = Left;
					return;
				}
			}
			else
			{
				if (isSelectedDirectionMovable(Left) && CurrentDirection != Right)
				{
					CurrentDirection = Left;
					return;
				}
				else if (isSelectedDirectionMovable(Right) && CurrentDirection != Left)
				{
					CurrentDirection = Right;
					return;
				}
			}
		}
	if (abs(GhostPosition_ptr->Y - Target.Y) > 30)
	{
		if (Target.Y < GhostPosition_ptr->Y && CurrentDirection != Down)//going up
		{
			if (isSelectedDirectionMovable(Up))
			{
				CurrentDirection = Up;
			}
			else
				TryLeftRight = true;
		}
		if (Target.Y > GhostPosition_ptr->Y && CurrentDirection != Up)
		{
			if (isSelectedDirectionMovable(Down))
			{
				CurrentDirection = Down;
			}
			else
				TryLeftRight = true;
		}
	}
	if (TryLeftRight || abs(GhostPosition_ptr->Y - Target.Y) < 30)
	{
		if (GhostPosition_ptr->X < Target.X)
		{
			if (isSelectedDirectionMovable(Right) && CurrentDirection != Left)
			{
				CurrentDirection = Right;
				TryLeftRight = false;
				return;
			}
			TryLeftRight = true;
		}
		else
		{
			if (isSelectedDirectionMovable(Left) && CurrentDirection != Right)
			{
				CurrentDirection = Left;
				TryLeftRight = false;
				return;
			}
			TryLeftRight = true;
		}
	}
	if (TryLeftRight)
	{
		RandomDirection();
	}
	//return CurrentDirection;
}

void GhostNavigator::SetTarget(const Vector2& target)
{
	Target = target;
}

//Direction GhostNavigator::FindDirectionInScaredMode()
//{
//	//return random direction;
//	return Right;
//}

bool GhostNavigator::isInsideTurningTiles()
{
	CircleSprite smallCircle(3.f, *GhostPosition_ptr);
	return Collision::CheckCollision(smallCircle, TurningTiles);
}

bool GhostNavigator::isSelectedDirectionMovable(const Direction& direction)
{
	Sprite tempSprite(30, 30, Vector2(0, 0));
	auto displace_test = 38.f;
	auto isMovable = true;
	auto temp = *GhostPosition_ptr;
	switch (direction)
	{
	case Up:
		temp.subtract(Vector2(0, displace_test));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls) || CheckCollisionWithaDoor(tempSprite))
			isMovable = false;
		break;
	case Down:
		temp.add(Vector2(0, displace_test));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls) || CheckCollisionWithaDoor(tempSprite))
			isMovable = false;
		break;
	case Right:
		temp.add(Vector2(displace_test, 0));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls) || CheckCollisionWithaDoor(tempSprite))
			isMovable = false;
		break;
	case Left:
		temp.subtract(Vector2(displace_test, 0));
		tempSprite.SetPosition(temp);
		if (Collision::CheckCollision(tempSprite, Walls) || CheckCollisionWithaDoor(tempSprite))
			isMovable = false;
		break;
	}
	return isMovable;
}

void GhostNavigator::RandomDirection()
{
	Direction temp;
	auto toInt = static_cast<int>(CurrentDirection);
	//this is to ensure that a randomly selected direction is not a reverse direction;
	if (toInt % 2 == 0) toInt -= 1;
	else
		toInt += 1;
	do {
		do {
			temp = static_cast<Direction>((rand() % 4) + 1);

		} while (static_cast<int>(temp) == toInt);
		StuckCount++;
		if (StuckCount > 10)
		{
			CurrentDirection = static_cast<Direction>(toInt);
			StuckCount = 0;
			return;
		}
	} while (!isSelectedDirectionMovable(temp));
	StuckCount = 0;
	CurrentDirection = temp;
}

bool GhostNavigator::CheckCollisionWithaDoor(const Sprite& rectangle) const
{
	for (auto Door : Doors)
	{
		if (Door->IsDoorLocked())
		{
			if (Collision::CheckCollision(rectangle, *Door)) return true;
		}
	}
	return false;
}

void GhostNavigator::SetCurrentDirection(const Direction& direction)
{
	CurrentDirection = direction;
}

Direction GhostNavigator::GetCurrentDirrection() const
{
	return CurrentDirection;
}
