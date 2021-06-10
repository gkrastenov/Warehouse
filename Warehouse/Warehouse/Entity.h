#pragma once
#include "DateTime.h"
#include "String.h"

class Entity
{
private:
	void copy(const Entity&);

protected:
	DateTime entryDate;
	String description;
	int quantity;

public:
	Entity();
	Entity(const Entity& other);
	Entity& operator=(const Entity& other);
	~Entity();

	void setDescription(const String& description);
	void setEntryDate(const char* entryDate);
	void setEntryDate(const DateTime& entryDate);
	void setQuantity(const int quantity);

	String getDescription() const;
	DateTime& getEntryDate();
	int getQuantity() const;

	virtual void print() = 0;
};