#include "PacMan.h"

PacMan::PacMan(const float& width, const float& height, const Vector2& postion): Sprite(width,height, postion)
{}

void PacMan::SetSpeed(const float& speed) {Speed = speed; }

unsigned int PacMan::IncreamentPoints(const unsigned int& points)
{
	CollectedPoints += points;
}
void PacMan::SetState(const State& state_)
{
	state = state_;
}
unsigned int PacMan::GetLifes() const { return Lifes; }

void PacMan::MoveUp()
{
	auto temp = GetPostion();
	temp.subtract(Vector2(0, Speed));
	SetPosition(temp);
}
void PacMan::MoveDown() {

	auto temp = GetPostion();
	temp.add(Vector2(0, Speed));
	SetPosition(temp);
}
void PacMan::MoveLeft()
{
	auto temp = GetPostion();
	temp.subtract(Vector2(Speed, 0));
	SetPosition(temp);
}
void PacMan::MoveRight()
{
	auto temp = GetPostion();
	temp.add(Vector2(Speed, 0));
	SetPosition(temp);
}
