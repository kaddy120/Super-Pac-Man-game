#pragma once
#include "Sprite.h"
#include "Movement.h"

enum class State {Alive, charged, SuperCharged, Dead };

//enum class Move { Up, Down, Right, Left, NotMoving};

class PacMan: public Sprite
{
public:
	PacMan(const float& width, const float& height, const Vector2& postion);
	void SetSpeed(const float& speed);
	unsigned int IncreamentPoints(const unsigned int& points);
	unsigned int GetPoints() const { return CollectedPoints; }
	void SetState(const State& state);
	unsigned int GetLifes() const;
	Vector2 Move(const Direction& direction);


private:	
	unsigned int CollectedPoints=0;
	unsigned int Lifes = 3;
	State state=State::Alive;
	Movement Movement_;

	//void MoveUp();
	//void MoveDown();
	//void MoveLeft();
	//void MoveRight();
};

