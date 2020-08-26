#pragma once
#include "sprite.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string>

class Key: public Sprite
{
public:
	Key();
	Key(const float& width, const float& height, const Vector2& postion);

	void SetKeyDimensions(const float& width, const float& height, const Vector2& postion);

	//i don't really want to copy a key but i want two doors to share a key.
	Key(const Key& key);
	
	bool operator ==(const Key& ) const;
	std::string GetKeyId() const;

private:
	std::string KeyId;
	std::string GenerateUniqueID();

};

