#pragma once
#include "Entity.h"
#include "String.h"

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
	Change(const String& description, const int quantity, const DateTime& date, const ChangeType type);
	~Change();

	int changeTypeToInt(const ChangeType type) const;
	void printChangeType(const ChangeType type) const;
	void print() override;
};