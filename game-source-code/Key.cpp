#include "Key.h"
#include <iostream>

Key::Key() {
	KeyId = GenerateUniqueID();
}

Key::Key(const float& radius, const Vector2& position) : CircleSprite(radius, position) {
	KeyId = GenerateUniqueID();
}

bool Key::operator ==(const Key& otherkey) const {
	return KeyId ==otherkey.GetKeyId();
}

std::string Key::GetKeyId() const { return KeyId; }

void Key::SetKeyDimensions(const float& radius, const Vector2& position)
{
	SetRadius(radius);
	SetPosition(position);
}

std::string Key::GenerateUniqueID() {
	std::string UniqueChar = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";

	std::string KeyId = "";
	for (int i = 0; i < 10; i++)
	{
		auto index = rand() % 43;
		KeyId += UniqueChar[index];
	}

	return KeyId;
}
