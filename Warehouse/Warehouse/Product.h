#pragma once
#include "Entity.h"
#include "String.h"

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
	String manufacturer;
	Unit unit;
	int location;
	String comment;

	void setDefaultValues();

public:
	const int MIN_DESCRIPTION = 2;
	const int MAX_DESCRIPTION = 50;

	const int MIN_MANUFACTURER = 2;
	const int MAX_MANUFACTURER = 50;

	const int MIN_QUANTITY = 1;
	const int MAX_QUANTITY = 10;

	const int MIN_LOCATION = 1;
	const int MAX_LOCATION = 100;

	const int MIN_COMMENT = 2;
	const int MAX_COMMENT = 200;

	Product();
	~Product();

	void setManufacturer(const String& manufacturer);
	void setExpiryDate(const char* expiryDate);
	void setExpiryDate(const DateTime& expiryDate);
	void setLocation(const int location);
	void setComment(const String& comment);
	void setUnit(const Unit unit);
	bool setUnit(const int unit);
	
	String getManufacturer() const;
	DateTime& getExpiryDate();
	int getLocation() const;
	String getComment() const;
	Unit getUnit() const;

	int unitToNumber(const Unit unit);
	void printUnit(const Unit unit);
	void print() override;

	Product& operator = (const Product& product);
};