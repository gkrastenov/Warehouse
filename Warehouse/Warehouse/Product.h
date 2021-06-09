#pragma once
#include "DateTime.h"

enum Unit
{
	Kilograms,
	Liters,
	Unknown
};

class Product
{
private:
	char* description;
	DateTime expiryDate;
	DateTime entryDate;
	char* manufacturer;
	Unit unit;
	int quantity;
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

	void setDescription(const char* description);
	void setManufacturer(const char* manufacturer);
	void setExpiryDate(const char* expiryDate);
	void setEntryDate(const char* entryDate);
	void setExpiryDate(const DateTime& expiryDate);
	void setEntryDate(const DateTime& entryDate);
	void setQuantity(const int quantity);
	void setLocation(const int location);
	void setComment(const char* comment);
	bool setUnit(const int unit);
	
	char* getDescription() const;
	char* getManufacturer() const;
	DateTime& getExpiryDate();
	DateTime& getEntryDate();
	int getQuantity() const;
	int getLocation() const;
	char* getComment() const;
	Unit getUnit() const;

	int unitToNumber(const Unit unit);
	void printUnit(const Unit unit);
	void print();

	Product& operator = (const Product& product);
	bool operator == (const Product& product);
};