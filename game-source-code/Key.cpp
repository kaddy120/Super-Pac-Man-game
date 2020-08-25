#include "Key.h"

Key::Key() {
	KeyId = reinterpret_cast<uint32_t>(this);
}

Key::Key(const float& width, const float& height, const Vector2& postion) : Sprite(width, height, postion) {
	KeyId = reinterpret_cast<uint32_t>(this);
}

//copy constructor
Key::Key(const Key& key) {
	KeyId = key.GetKeyId();
}

bool Key::operator ==(const Key& other) const {
	if (this->KeyId == other.GetKeyId)
		return true;
	else
		return false;
}

uint32_t Key::GetKeyId() const { return KeyId; }

void Key::SetKeyDimensions(const float& width, const float& height, const Vector2& postion)
{

}
