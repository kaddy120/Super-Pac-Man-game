#include "Door.h"

Door::Door() {
}

Door::Door(const float& width, const float& height, const Vector2& postion) : Sprite(width, height, postion)
{}

void Door::AssignKey(const Key& key_)
{
	key = key_;
	hasKey = true;
}

bool Door::Unlock(const Key& key_)
{
	if (key_ == key)
	{
		Unlocked = false;
		return true;
	}
	else
		return false;
}

bool Door::IsDoorLocked() const {
	return Unlocked; 
}
bool Door::HasKey() const {
	return hasKey;
}

