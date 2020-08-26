#include "GameMap.h"

GameMap::GameMap()
{
	//[25][23]
	Maize = {
	{ "o","h","o","h","o","h","o","h","o","h","o","h", "o","h","o","h","o","h","o","h","o","h","o" },
	{ "v","k","o","t","o","t","o","n","o","n","o","n", "o","t","o","n","o","t","o","t","o","k","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","d", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","n","v","p","v","n","D","f","o","f","o","f", "o","f","o","f","D","n","v","p","v","n","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","d", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","t","o","t","o","t","o","n","o","n","o","t", "o","n","o","n","o","t","o","k","o","t","v" },
	{ "o","n","o","d","o","h","o","n","o","h","o","d", "o","h","o","n","o","h","o","d","o","n","o" },
	{ "v","n","v","f","o","f","v","n","v","n","o","n", "o","n","v","n","v","f","o","f","v","n","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","n", "o","n","o","n","o","n","o","d","o","n","o" },
	{ "v","k","o","n","v","f","v","n","v","n","o","n", "o","n","v","n","v","f","v","n","o","k","v" },
	{ "o","h","o","n","o","n","o","n","o","h","o","h", "o","h","o","n","o","n","o","n","o","h","o" },
	{ "D","f","o","n","o","f","D","n","o","n","o","n", "o","n","o","n","D","f","D","n","D","f","D" },
	{ "o","h","o","n","o","h","o","n","o","h","o","n", "o","h","o","n","o","h","o","n","o","h","o" },
	{ "v","n","o","n","o","n","o","n","v","n","v","n", "v","n","v","n","o","n","o","n","o","k","v" },
	{ "o","n","o","d","o","n","o","d","o","h","o","n", "o","h","o","d","o","n","o","d","o","n","o" },
	{ "v","n","v","f","v","n","v","P","o","f","o","n", "D","f","o","P","v","n","v","f","v","n","v" },
	{ "o","n","o","n","o","n","o","d","o","h","o","n", "o","h","o","n","o","n","o","n","o","n","o" },
	{ "v","n","v","f","v","n","v","f","v","n","o","k", "o","n","v","f","v","n","v","f","v","n","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","h", "o","n","o","n","o","n","o","d","o","n","o" },
	{ "v","n","o","n","o","n","v","f","v","n","v","f", "v","n","v","f","v","n","o","n","o","n","v" },
	{ "o","n","o","d","o","n","o","n","o","n","o","d", "o","n","o","d","o","n","o","d","o","n","o" },
	{ "v","n","v","p","v","k","o","n","o","n","o","n", "o","n","o","n","o","k","v","p","v","n","v" },
	{ "o","n","o","d","o","n","o","h","o","h","o","d", "o","h","o","h","o","n","o","d","o","n","o" },
	{ "v","k","o","n","o","n","D","f","o","f","o","f", "o","f","o","f","D","n","o","n","o","n","v" },
	{ "o","h","o","h","o","h","o","h","o","h","o","h", "o","h","o","h","o","h","o","h","o","h","o" }
	};

	Map();
}

void GameMap::Map()
{
	Vector2 position(0,0);
	Vector2 VerticalIncremet(0.f,60.f);
	Vector2 HorizontalIncrement(60,0);
	float width_ = 60;
	float height_ = 8;
	float width = 8;
	float height = 60;
	Sprite Wall_h(width_, height_, position);
	
	for (auto row=0; row < Maize.size(); row++)
	//for (auto row = 0; row < 1; row++)
	{
		if (Maize[row][0] == "o")
			position.add(VerticalIncremet);
		position.X = 0.f;

		for (auto col=0; col <Maize[row].size(); col++ )
		{
			auto condition = Maize[row][col];
			if (condition == "o")
			{

			}
			else if (condition == "h")
			{
				Walls.push_back(Sprite(width_,height_, position));
				position.add(HorizontalIncrement);
			}
			else if (condition == "v")
			{
				Walls.push_back(Sprite(width, height, position));
				//position.add(HorizontalIncrement);
			}
			else if (condition == "D")
			{
				Walls.push_back(Sprite(width, height, position));
			}
			else if (condition == "n")
			{
				position.add(HorizontalIncrement);
			}
			else if(condition =="f")
			{
				position.add(HorizontalIncrement);
			}
			else if (condition == "k")
			{
				position.add(HorizontalIncrement);
			}
			else if (condition == "t")
			{
				position.add(HorizontalIncrement);
			}
			else if (condition == "d")
			{
				position.add(HorizontalIncrement);
			}
			else if (condition == "P")
			{
				position.add(HorizontalIncrement);
			}
			else if (condition == "p")
			{
				position.add(HorizontalIncrement);
			}
		}
	}
}

std::vector<Sprite> GameMap::GetWalls() const { return Walls; }

