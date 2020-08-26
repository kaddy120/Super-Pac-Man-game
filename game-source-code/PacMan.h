#pragma once
#include "Sprite.h"

enum class State {Alive, charged, SuperCharged, Dead };

//enum class Direction { Up, Down, Right, Left };

class PacMan: public Sprite
{
public:
	PacMan(const float& width, const float& height, const Vector2& postion);
	void SetSpeed(const float& speed);
	unsigned int IncreamentPoints(const unsigned int& points);
	void SetState(const State& state);
	unsigned int GetLifes() const;
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

private:	
	float Speed= 1.0f; 
	unsigned int CollectedPoints=0;
	unsigned int Lifes = 3;
	State state=State::Alive;
};

