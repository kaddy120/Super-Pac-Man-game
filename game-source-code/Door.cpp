#include "Door.h"

Door::Door() {
}

Door::Door(const float& width, const float& height, const Vector2& postion) : Sprite(width, height, postion)
{}

Door::Door(const Door& door) {
	key = door.GetKey();
}

bool Door::Unlock(const Key& key_)
{
	if (key_ == key)
	{
		Unlocked = true;
		return true;
	}
	else
		return false;
}

bool Door::IsDoorLocked() const { return Unlocked; }
