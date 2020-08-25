#pragma once
#include "Sprite.h"
#include "Key.h"
#include "Vector2.h"

class Door: public Sprite
{
public:
	Door();
	Door(const float& width, const float& height, const Vector2& postion);

	Door(const Door& door);

	Key GetKey() const { return key;}

	bool Unlock(const Key& key_);
	bool IsDoorLocked() const;

private:
	Key key;
	bool Unlocked = false;
		
};

