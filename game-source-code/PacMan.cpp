#include "PacMan.h"

PacMan::PacMan(const float& width, const float& height, const Vector2& postion): Sprite(width,height, postion),
Movement_()
{}

void PacMan::SetSpeed(const float& speed) {Movement_.SetSpeed(speed); }

unsigned int PacMan::IncreamentPoints(const unsigned int& points)
{
	CollectedPoints += points;
	return CollectedPoints;
}
void PacMan::SetState(const State& state_)
{
	state = state_;
	if (state_ == State::Dead)
	{
		Lifes--;
	}
}
Vector2 PacMan::Move(const Direction& direction)
{
    return Movement_.Move(GetPosition_ptr(),direction);
}

unsigned int PacMan::GetLifes() const { return Lifes; }


