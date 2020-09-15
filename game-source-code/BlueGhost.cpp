//
//#include "BlueGhost.h"
//
//BlueGhost::BlueGhost(
//	const std::vector<CircleSprite>& turningTiles,
//	const std::vector<Sprite>& walls,
//	const std::vector<std::shared_ptr<Door>>& Doors,
//	const float& radius,
//	const Vector2& initPosition) : GhostAbstract(turningTiles, walls, Doors, radius, initPosition) {}
//
//void BlueGhost::Movement()
//{
//	SetChaseMode();
//	switch (Mode_)
//	{
//	case Mode::Chase:
//		SetTarget();
//		ChaseTargetMovement();
//		break;
//	case Mode::Captured:
//		Target = DoorPostion;
//		ChaseTargetMovement();
//		break;
//	case Mode::Scatter:
//		Target = ScatterPosition;
//		ChaseTargetMovement();
//		break;
//	case Mode::Frightened:
//		ScaredMovement();
//		break;
//	default:
//		break;
//	}
//}
//
//void BlueGhost::SetTarget()
//{
//	CircleSprite WithinRangeCircle{ 230, GetPosition() };
//	CircleSprite tempCircle{ 1, *PacManPostion };
//	auto position_ = GetPosition();
//	if (Collision::CheckCollision(WithinRangeCircle, tempCircle))
//	{
//		Target = *PacManPostion;
//	}
//
//	else
//		Target = *PacManPostion;
//}
//
//void BlueGhost::SetRedGhostPosition(const std::shared_ptr<Vector2>& position)
//{
//	RedGhostPositionIsSet = true;
//	RedGhostPosition = position;
//}
