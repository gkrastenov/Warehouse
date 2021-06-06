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

public:
	const int MAX_DESCRIPTION_LENGTH = 150;
	const int MAX_MANUFACTURER_LENGTH = 50;
	const int MAX_COMMENT_LENGTH = 300;

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
	void printProduct();

	Product& operator = (const Product& product);
};
