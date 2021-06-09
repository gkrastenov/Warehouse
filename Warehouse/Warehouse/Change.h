#pragma once
#include "Entity.h"

enum class ChangeType
{
	Add = 0,
	Remove = 1,
	Clean = 2,
	Undefined = 3
};
class Change :
	public Entity
{
private:
	ChangeType type;
public:
	bool setChangeType(const int type);
	void setChangeType(const ChangeType type);
	ChangeType getChangeType() const;
	
	Change();
	~Change();

	void printChangeType(const ChangeType type) const;
	void print() override;
};

