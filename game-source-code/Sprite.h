#pragma once
#ifndef sprite_h
#define sprite_h
#include "Vector2.h"
#include <tuple>
#include "string"
#include <memory>
#include "IEntity.h"

class Sprite: public IEntity
{
public:
	Sprite();
	Sprite(const float& width, const float& height, const Vector2& postion);
	std::shared_ptr<Vector2> GetPosition_ptr() const override;
	void SetPosition(const Vector2& position) override; 
	Vector2 GetPosition() const override;
	Vector2 GetCenter();
	//return {Heigh, Width}
	std::tuple<float, float> getDimentions() const;
	void SetDimensions(const float& width, const float& height);

	const std::string& Name() const { return name; }
	void Name(const std::string& name_) { name = name_; }

private:
	std::string name ="";
	float Width;
	float Height;
	//relative to the upleft-conner
	std::shared_ptr<Vector2> position;
	Vector2 Center;
};

#endif

