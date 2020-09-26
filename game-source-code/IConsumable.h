#pragma once

class IConsumable {
public:
	virtual void SetPoints() = 0;
	virtual void GetPoints() = 0;
};