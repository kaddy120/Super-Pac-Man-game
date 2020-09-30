#include "AbstractGhost.h"

AbstractGhost::AbstractGhost(
	const std::vector<CircleSprite>& turningTiles,
	const std::vector<Sprite>& walls,
	const std::vector<std::shared_ptr<Door>>& doors,
	const float& radius,
	const Vector2& initPosition) :CircleSprite(radius, initPosition), Navigator(
		turningTiles,
		walls,
		doors,
		GetPosition_ptr()) {
	StartTime = std::chrono::steady_clock::now();
}

void AbstractGhost::Move()
{
	if(Mode_ != Mode::Eaten && Mode_!= Mode::Frightened)
	SetChaseMode();
	switch (Mode_)
	{
	case Mode::Chase:
		SetTarget();
		ChaseTargetMovement();
		break;
	case Mode::Eaten:
		Navigator.SetTarget(DoorPosition);
		ChaseTargetMovement();
		break;
	case Mode::Scatter:
		Navigator.SetTarget(ScatterPosition);
		ChaseTargetMovement();
		break;
	case Mode::Frightened:
		ScaredMovement();
		break;
	default:
		break;
	}
}
Mode AbstractGhost::GetMode() const
{
	return Mode_;
}

void AbstractGhost::UpdateMode(const Mode& mode)
{
	if (mode == Mode::Frightened)
	{
		auto toInt = (int)Navigator.GetCurrentDirrection();
		//this is to ensure that a randomly selected direction is not a reverse direction;
		if (toInt % 2 == 0) toInt -= 1;
		else
			toInt += 1;
		Navigator.SetCurrentDirection(static_cast<Direction>(toInt));
	}
	Mode_ = mode;
}

void AbstractGhost::SetPackManPosition(const std::shared_ptr<Vector2>& position)
{
	PacManPosition = position;
}

void AbstractGhost::ScaredMovement()
{
	Movement_.Move(GetPosition_ptr(),Navigator.GetCurrentDirrection());
	
	auto isInside_turningTile = Navigator.isInsideTurningTiles();
	if (isInside_turningTile && Clock_.TimeLapse()>0.4)
	{
		///is either i'll use count or time
		Navigator.RandomDirection();
		Clock_.Reset();
	}
}

void AbstractGhost::ChaseTargetMovement()
{
	//if(isSelectedDirectionMovable(CurrentDirection))
	Movement_.Move(GetPosition_ptr(), Navigator.GetCurrentDirrection());
	auto isInside_turningTile = Navigator.isInsideTurningTiles();
	if (isInside_turningTile && count_ >= 30)
	{
		Movement_.Move(GetPosition_ptr(), Navigator.GetCurrentDirrection());
		//Movement_.Move(GetPosition_ptr(), Navigator.GetCurrentDirrection());
		Navigator.FindDirectionToTarget();
		count_ = 0;
	}
	count_++;
}
//this can move out
void AbstractGhost::SetChaseMode()
{
	auto Now = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsed_seconds = Now - StartTime;
	//auto duration = 7;
	auto elapsed_second = elapsed_seconds.count();
	if (elapsed_seconds.count() < 7)
	{
		Mode_ = Mode::Scatter;
	}
	else if (elapsed_second < 27)
	{
		Mode_ = Mode::Chase;
	}
	else if (elapsed_second < 34)
	{
		Mode_ = Mode::Scatter;
	}
	else if (elapsed_second < 54)
	{
		Mode_ = Mode::Chase;
	}
	else if (elapsed_second < 59)
	{
		Mode_ = Mode::Scatter;
	}
	else if (elapsed_second < 79)
	{
		Mode_ = Mode::Chase;

	}
	else if (elapsed_second < 84)
	{
		Mode_ = Mode::Scatter;
	}
	else
		Mode_ = Mode::Chase;
}

void AbstractGhost::SetSpeed(const float& speed)
{
	Movement_.SetSpeed(speed);
}