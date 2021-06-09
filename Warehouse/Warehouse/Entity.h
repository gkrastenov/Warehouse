#pragma once
#include<iostream>
#include "DateTime.h"

class Entity
{
private:
	void copy(const Entity&);

protected:
	DateTime entryDate;
	char* description;
	int quantity;

public:
	Entity();
	Entity(const Entity& other);
	Entity& operator=(const Entity& other);
	~Entity();

	void setDescription(const char* description);
	void setEntryDate(const char* entryDate);
	void setEntryDate(const DateTime& entryDate);
	void setQuantity(const int quantity);

	char* getDescription() const;
	DateTime& getEntryDate();
	int getQuantity() const;

	virtual void print() = 0;
};