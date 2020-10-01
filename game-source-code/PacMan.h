#pragma once
#include "Sprite.h"
#include "Movement.h"
#include "Definitions.h"

class PacMan: public Sprite
{
public:
	PacMan(const float& width, const float& height, const Vector2& postion);
	void SetSpeed(const float& speed);
	unsigned int IncreamentPoints(const unsigned int& points);
	unsigned int GetPoints() const { return CollectedPoints; }
	void SetState(const State& state);
	State GetSate() const;
	unsigned int GetLifes() const;
	Vector2 Move(const Direction& direction);
	void SubtractLife();
	void ResetPoints() { CollectedPoints = 0; }

private:	
	unsigned int CollectedPoints=0;
	unsigned int Lifes = 3;
	State state=State::Alive;
	Movement Movement_;
};

