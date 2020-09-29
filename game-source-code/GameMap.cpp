#include "GameMap.h"

GameMap::GameMap()
{
	//[25][23]
	Maize = {
	{ "o","h","o","h","o","h","o","h","o","h","o","h", "o","h","o","h","o","h","o","h","o","h","o" },
	{ "v","k","o","t","o","t","o","n","o","n","o","t", "o","n","o","n","o","k","o","t","o","k","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","d", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","n","v","p","v","n","D","f","o","f","o","f", "o","f","o","f","D","n","v","p","v","n","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","h", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","t","o","k","o","t","o","t","o","n","o","t", "o","n","o","t","o","t","o","k","o","t","v" },
	{ "o","n","o","d","o","h","o","n","o","h","o","d", "o","h","o","n","o","h","o","d","o","n","o" },
	{ "v","n","v","f","o","f","v","n","v","t","o","n", "o","t","v","n","v","f","o","f","v","n","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","n", "o","n","o","n","o","n","o","d","o","n","o" },
	{ "v","k","o","t","v","f","v","n","v","t","o","t", "o","t","v","n","v","f","v","t","o","k","v" },
	{ "o","h","o","n","o","n","o","n","o","h","o","h", "o","h","o","n","o","n","o","n","o","h","o" },
	{ "D","f","o","t","o","f","D","t","o","n","o","t", "o","n","o","t","D","f","D","t","D","f","D" },
	{ "o","h","o","n","o","h","o","n","o","h","o","n", "o","h","o","n","o","h","o","n","o","h","o" },
	{ "v","t","o","t","o","t","o","t","v","n","v","n", "v","n","v","t","o","t","o","t","o","k","v" },
	{ "o","n","o","d","o","n","o","d","o","h","o","n", "o","h","o","d","o","n","o","d","o","n","o" },
	{ "v","n","v","f","v","n","v","P","o","f","o","t", "D","f","o","P","v","n","v","f","v","n","v" },
	{ "o","n","o","n","o","n","o","n","o","h","o","n", "o","h","o","n","o","n","o","n","o","n","o" },
	{ "v","n","v","f","v","n","v","f","v","t","o","k", "o","t","v","f","v","n","v","f","v","n","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","h", "o","n","o","n","o","n","o","d","o","n","o" },
	{ "v","t","o","t","o","t","v","f","v","n","v","n", "v","n","v","f","v","t","o","t","o","t","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","h", "o","n","o","d","o","n","o","d","o","n","o" },
	{ "v","n","v","p","v","k","o","t","o","t","o","t", "o","t","o","t","o","k","v","p","v","n","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","d", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","k","o","t","o","t","D","f","o","f","o","f", "o","f","o","f","D","t","o","t","o","k","v" },
	{ "o","h","o","h","o","h","o","h","o","h","o","h", "o","h","o","h","o","h","o","h","o","h","o" }
	};

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
	Sprite Wall_h(width_, height_, position);

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
				auto wall = Sprite(width_, height_, position);
				wall.Name("Wall");
				Walls.push_back(wall);
				position.add(HorizontalIncrement);
			}
			else if (condition == "v")
			{
				auto wall = Sprite(width, height, position);
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
			else if (condition == "k")
			{
				tempPosition.X = position.X;
				tempPosition.add(CircleHorizontalIncrement);
				TurningPoints.push_back(CircleSprite(2.f, tempPosition));
				Keys.push_back(Key(4.f, tempPosition));
				position.add(HorizontalIncrement);

			}
			else if (condition == "t")
			{
				//i can refactor most of this code into  a private functions
				tempPosition.X = position.X;
				tempPosition.add(CircleHorizontalIncrement);
				TurningPoints.push_back(CircleSprite(3.f, tempPosition));
				position.add(HorizontalIncrement);
			}
			else if (condition == "P")
			{
				tempPosition.X = position.X;
				tempPosition.add(CircleHorizontalIncrement);
				TurningPoints.push_back(CircleSprite(3.f, tempPosition));
				SuperPallets.push_back(SuperPallet(16.f, tempPosition));
				position.add(HorizontalIncrement);
			}
			else if (condition == "p")
			{
				tempPosition.X = position.X;
				tempPosition.add(CircleHorizontalIncrement);
				auto pallet = SuperPallet(15.f, tempPosition);
				pallet.Name("PowerPallet");
				PowerPallets.push_back(pallet);
				position.add(HorizontalIncrement);
			}
		}
	}
}

std::vector<Sprite> GameMap::GetWalls() const { 
	return Walls; 
}
vector<CircleSprite> GameMap::GetTurningPoinints() const { 
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

vector<SuperPallet> GameMap::GetSuperPallets() const {
	return SuperPallets; 
}

vector<SuperPallet> GameMap::GetPowerPallets() const {
	return PowerPallets;
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
			CircleSprite RangeCircle(120, key.GetPosition());
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





