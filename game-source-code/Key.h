#pragma once
#include "sprite.h"

class Key: public Sprite
{
public:
	Key();
	Key(const float& width, const float& height, const Vector2& postion);

	void SetKeyDimensions(const float& width, const float& height, const Vector2& postion);

	bool operator ==(const Key& other) const;
	//i don't really want to copy a key but i want two doors to share a key.
	Key(const Key& key);
	
	uint32_t GetKeyId() const;

private:
	uint32_t KeyId = 0;
};

