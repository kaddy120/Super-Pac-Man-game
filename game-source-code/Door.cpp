#include "Door.h"
#include <iostream>

Door::Door() {
	Name("Door");
}

Door::Door(const float& width, const float& height, const Vector2& postion) : Sprite(width, height, postion)
{
	Name("Door");
}

void Door::AssignKey(const Key& key_)
{
	key = key_;
	hasKey = true;
}

bool Door::Unlock(const Key& key_)
{
	if (key_ == key)
	{
		locked = false;
		return true;
	}
	else
		return false;
}

bool Door::IsDoorLocked() const {
	return locked; 
}
bool Door::HasKey() const {
	return hasKey;
}

