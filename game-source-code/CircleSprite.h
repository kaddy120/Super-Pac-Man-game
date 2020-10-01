#pragma once
#include "string"
#include "Vector2.h"
#include <memory>
#include "IEntity.h"

class CircleSprite: public IEntity
{
public:
	CircleSprite();
	CircleSprite(const float& radius, const Vector2& postion);
	Vector2 GetPosition() const override;
	std::shared_ptr<Vector2> GetPosition_ptr() const override;
	void SetPosition(const Vector2& position) override;
	float GetRadius() const;

	void SetRadius(const float& radius);

	const std::string& Name() const { return name; }

	void Name(const std::string& name_) { name = name_; }

private:
	std::string name = "";
	float Radius;
	std::shared_ptr<Vector2> PositionCenter;
};

