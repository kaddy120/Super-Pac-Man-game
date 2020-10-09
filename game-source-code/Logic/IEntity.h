#pragma once
#include <memory>
#include "Vector2.h"

class IEntity
{
public:
	virtual std::shared_ptr<Vector2> GetPosition_ptr() const = 0;
	virtual Vector2 GetPosition() const = 0;
	virtual void SetPosition(const Vector2& position) = 0;
};