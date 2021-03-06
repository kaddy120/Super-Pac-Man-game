#include "GameMap.h"

GameMap::GameMap()
{
	//[25][23]
	Maize = {
	{ "o","h","o","h","o","h","o","h","o","h","o","h", "o","h","o","h","o","h","o","h","o","h","o" },
	{ "v","k","o","t","o","t","o","n","o","n","o","k", "o","n","o","n","o","t","o","t","o","k","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","d", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","n","v","p","v","t","D","F","o","f","o","F", "o","f","o","F","D","k","v","p","v","n","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","h", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","t","o","k","o","t","o","t","o","n","o","t", "o","n","o","t","o","t","o","k","o","t","v" },
	{ "o","n","o","d","o","h","o","n","o","h","o","GD","o","h","o","n","o","h","o","d","o","n","o" },
	{ "v","n","v","F","o","F","v","n","v","t","o","n", "o","t","v","n","v","F","o","F","v","n","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","n", "o","n","o","n","o","n","o","d","o","n","o" },
	{ "v","k","o","t","v","f","v","n","v","t","o","t", "o","t","v","n","v","f","v","t","o","k","v" },
	{ "o","h","o","n","o","n","o","n","o","h","o","h", "o","h","o","n","o","n","o","n","o","h","o" },
	{ "O","t","D","t","o","F","v","t","o","n","o","t", "o","n","o","t","D","F","D","t","D","F","o" },
	{ "o","h","o","n","o","h","o","n","o","h","o","n", "o","h","o","n","o","h","o","n","o","h","o" },
	{ "v","k","o","t","o","t","o","t","v","n","v","n", "v","n","v","k","o","t","o","t","o","k","v" },
	{ "o","n","o","d","o","n","o","d","o","h","o","n", "o","h","o","d","o","n","o","d","o","n","o" },
	{ "v","n","v","F","v","n","v","P","o","f","o","t", "D","F","o","P","v","n","v","F","v","n","v" },
	{ "o","n","o","n","o","n","o","n","o","h","o","n", "o","h","o","n","o","n","o","n","o","n","o" },
	{ "v","n","v","F","v","n","v","f","v","t","o","k", "o","t","v","f","v","n","v","F","v","n","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","h", "o","n","o","n","o","n","o","d","o","n","o" },
	{ "v","t","o","t","o","k","v","f","v","n","v","n", "v","n","v","F","v","t","o","t","o","t","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","h", "o","n","o","d","o","n","o","d","o","n","o" },
	{ "v","n","v","p","v","t","o","t","o","t","o","k", "o","t","o","t","o","k","v","p","v","n","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","d", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","t","o","t","o","k","D","F","o","f","o","F", "o","f","o","F","v","t","o","t","o","t","v" },
	{ "o","h","o","h","o","h","o","h","o","h","o","h", "o","h","o","h","o","h","o","h","o","h","o" }};

	Map();
	AssignKeyToDoor();
}

void GameMap::Map()
{
	Vector2 position(0,80);
	Vector2 VerticalIncremet(0.f,60.f);
	Vector2 CircleVerticalIncrement(0.f, 24.f);
	Vector2 HorizontalIncrement(60,0);
	Vector2 CircleHorizontalIncrement(24.f, 0);

	float width_ = 68;
	float height_ = 8;
	float width = 8;
	float height = 68;
	RectangularEntity Wall_h(width_, height_, position);

	auto tempPosition = position;///////////////////
	
	for (auto row=0; row < Maize.size(); row++)
	{
		
		if (Maize[row][0] == "o")
		{
			position.add(VerticalIncremet);
			tempPosition = position;
			tempPosition.add(CircleVerticalIncrement);
		}
		position.X = 0.f;
		
		for (auto col=0; col <Maize[row].size(); col++ )
		{
			auto condition = Maize[row][col];
			if (condition == "h")
			{
				auto wall = RectangularEntity(width_, height_, position);
				wall.Name("Wall");
				Walls.push_back(wall);
				position.add(HorizontalIncrement);
			}
			else if (condition == "v")
			{
				auto wall = RectangularEntity(width, height, position);
				wall.Name("Wall");
				Walls.push_back(wall);
			}
			else if (condition == "D")
			{
				Doors.push_back(std::make_shared<Door>(width, height, position));
			}
			else if (condition == "d")
			{
				Doors.push_back(std::make_shared<Door>(width_, height_, position));
				position.add(HorizontalIncrement);
			}
			else if (condition == "GD")
			{
			   GhostsHouseDoor_ = Door(width_, height_, position);
			   position.add(HorizontalIncrement);
			}
			else if (condition == "n")
			{
				position.add(HorizontalIncrement);
			}
			else if(condition =="f")
			{
				tempPosition = position;
				tempPosition.add(CircleHorizontalIncrement);
				tempPosition.add(CircleVerticalIncrement);
				Fruits.push_back(Fruit(15.f, tempPosition));
				position.add(HorizontalIncrement);
			}
			else if(condition =="F")
			{
				tempPosition = position;
				tempPosition.add(CircleHorizontalIncrement);
				tempPosition.add(CircleVerticalIncrement);
				TurningPoints.push_back(CircularEntity(3.f, tempPosition));
				Fruits.push_back(Fruit(15.f, tempPosition));
				position.add(HorizontalIncrement);
			}
			else if (condition == "k")
			{
				tempPosition.X = position.X;
				tempPosition.add(CircleHorizontalIncrement);
				TurningPoints.push_back(CircularEntity(2.f, tempPosition));
				Keys.push_back(Key(4.f, tempPosition));
				position.add(HorizontalIncrement);

			}
			else if (condition == "t")
			{
				tempPosition.X = position.X;
				tempPosition.add(CircleHorizontalIncrement);
				TurningPoints.push_back(CircularEntity(3.f, tempPosition));
				position.add(HorizontalIncrement);
			}
			else if (condition == "P")
			{
				tempPosition.X = position.X;
				tempPosition.add(CircleHorizontalIncrement);
				TurningPoints.push_back(CircularEntity(3.f, tempPosition));
				Pellets.push_back(Pellet(16.f, tempPosition));
				position.add(HorizontalIncrement);
			}
			else if (condition == "p")
			{
				tempPosition.X = position.X;
				tempPosition.add(CircleHorizontalIncrement);
				auto pallet = Pellet(15.f, tempPosition);
				pallet.Name("PowerPallet");
				PowerPallets.push_back(pallet);
				position.add(HorizontalIncrement);
			}
		}
	}
}

std::vector<RectangularEntity> GameMap::GetWalls() const { 
	return Walls; 
}
vector<CircularEntity> GameMap::GetTurningPoinints() const { 
	return TurningPoints; 
}
vector<std::shared_ptr<Door>> GameMap::GetDoors() const {
	return Doors; 
}
vector<Key> GameMap::GetKeys() const { 
	return Keys;
}

vector<Fruit> GameMap::GetFruits() const {
	return Fruits;
}

vector<Pellet> GameMap::GetPellets() const {
	return Pellets; 
}

vector<Pellet> GameMap::GetPowerPallets() const {
	return PowerPallets;
}
Door GameMap::GhostsHouseDoor() const {
	return GhostsHouseDoor_;
}


void GameMap::AssignKeyToDoor()
{
	for (auto key: Keys)
	{
		auto count = 0;
		for (auto i =0 ; i< Doors.size(); i++)
		{
			if (count >= 3)
				break;
			CircularEntity RangeCircle(120, key.GetPosition());
			if (Collision::CheckCollision(RangeCircle, *Doors[i]))
			{
				if (!Doors[i]->HasKey())
				{
					Doors[i]->AssignKey(key);
					count++;
				}
			}
		}
	}
}





