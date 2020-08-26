#include "Key.h"

Key::Key() {
	KeyId = GenerateUniqueID();
}

Key::Key(const float& width, const float& height, const Vector2& postion) : Sprite(width, height, postion) {
	KeyId = GenerateUniqueID();
}

//copy constructor
Key::Key(const Key& key) {
	KeyId = key.GetKeyId();
}

bool Key::operator ==(const Key& otherkey) const {
	return KeyId ==otherkey.GetKeyId();
}

std::string Key::GetKeyId() const { return KeyId; }

void Key::SetKeyDimensions(const float& width, const float& height, const Vector2& postion)
{

}

std::string Key::GenerateUniqueID() {
	std::string UniqueChar = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";

	srand(time(NULL));
	std::string KeyId = "";
	for (int i = 0; i < 10; i++)
	{
		auto index = rand() % 43 + 1;
		KeyId += UniqueChar[index];
	}
	return KeyId;
}
