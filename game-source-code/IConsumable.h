#pragma once

class IConsumable {
public:
	virtual unsigned int GetPoints() const = 0;
	virtual void SetPoints(const unsigned int& points) = 0;
};