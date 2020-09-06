#pragma once
#include "sprite.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <string>
#include "CircleSprite.h"

class Key: public CircleSprite
{
public:
	Key();
	Key(const float& radius, const Vector2& postion);

	void SetKeyDimensions(const float& radius, const Vector2& postion);

	//Key(const Key& key);
	
	bool operator ==(const Key& other) const;
	std::string GetKeyId() const;

private:
	std::string KeyId;
	std::string GenerateUniqueID();

};

