#include "Movement.h"
#include "Definitions.h"

Movement::Movement(const float& speed): Speed(speed) {}

void Movement::SetSpeed(const float& speed)
{
	Speed = speed;
}

Vector2 Movement::Move(std::shared_ptr<Vector2> Position, const Direction& direction)
{
	switch (direction)
	{
	case Up:
		Position->subtract(Vector2(0, Speed));
		break;
	case Down:
		Position->add(Vector2(0, Speed));
		break;
	case Right:
		Position->add(Vector2(Speed, 0));
		break;
	case Left:
		Position->subtract(Vector2(Speed, 0));
		break;
	}
	return *Position;
}