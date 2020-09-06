#pragma once
#include "Sprite.h"
#include "Key.h"
#include "Vector2.h"

class Door: public Sprite
{
public:
	Door();
	Door(const float& width, const float& height, const Vector2& postion);

	Key GetKey() const { return key;}
	void AssignKey(const Key& key);
	bool HasKey() const;
	bool Unlock(const Key& key);
	bool IsDoorLocked() const;

private:
	Key key;
	bool Unlocked = false;
	bool hasKey = false;
		
};

