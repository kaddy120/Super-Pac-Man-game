#include "PacMan.h"

PacMan::PacMan(const float& width, const float& height, const Vector2& postion): RectangularEntity(width,height, postion),
Movement_()
{}

void PacMan::SetSpeed(const float& speed) {Movement_.SetSpeed(speed); }

void PacMan::Die()
{
	if(Lifes >=0)
	Lifes--;
	if (Lifes == 0)
	{
		state = State::Dead;
		CollectedPoints = 0;
	}
}

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

State PacMan::GetState() const
{
	return state;
}

Vector2 PacMan::Move(const Direction& direction)
{
    return Movement_.Move(GetPosition_ptr(),direction);
}

unsigned int PacMan::GetLives() const { return Lifes; }


