#pragma once
#include "Entity.h"

enum class Unit
{
	Kilograms,
	Liters,
	Unknown
};

class Product :
	public Entity
{
private:
	DateTime expiryDate;
	char* manufacturer;
	Unit unit;
	int location;
	char* comment;

	void setDefaultValues();

public:
	const int MIN_DESCRIPTION = 2;
	const int MAX_DESCRIPTION = 50;

	const int MIN_MANUFACTURER = 5;
	const int MAX_MANUFACTURER = 50;

	const int MIN_QUANTITY = 1;
	const int MAX_QUANTITY = 10;

	const int MIN_LOCATION = 1;
	const int MAX_LOCATION = 100;

	const int MIN_COMMENT = 2;
	const int MAX_COMMENT = 200;

	Product();
	~Product();

	void setManufacturer(const char* manufacturer);
	void setExpiryDate(const char* expiryDate);
	void setExpiryDate(const DateTime& expiryDate);
	void setLocation(const int location);
	void setComment(const char* comment);
	void setUnit(const Unit unit);
	bool setUnit(const int unit);
	
	char* getManufacturer() const;
	DateTime& getExpiryDate();
	int getLocation() const;
	char* getComment() const;
	Unit getUnit() const;

	int unitToNumber(const Unit unit);
	void printUnit(const Unit unit);
	void print() override;

	Product& operator = (const Product& product);
	bool operator == (const Product& product);
};