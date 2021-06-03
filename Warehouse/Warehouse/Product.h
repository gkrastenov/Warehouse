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

	bool isNumber(const char symbol);
	int charToInt(const char symbol);
public:
	const int MAX_DESCRIPTION_LENGTH = 150;
	const int MAX_MANUFACTURER_LENGTH = 50;
	const int MAX_COMMENT_LENGTH = 300;

	Product();
	~Product();

	void setDescription(const char* description);
	void setManufacturer(const char* manufacturer);
	bool setExpiryDate(const char* expiryDate);
	bool setEntryDate(const char* entryDate);
	void setExpiryDate(const DateTime& expiryDate);
	void setEntryDate(const DateTime& entryDate);
	void setQuantity(const int quantity);
	void setLocation(const int location);
	void setComment(const char* comment);
	bool setUnit(const int unit);
	
	char* getDescription();
	char* getManufacturer();
	DateTime& getExpiryDate();
	DateTime& getEntryDate();
	int getQuantity();
	int getLocation();
	char* getComment();
	Unit getUnit();

	int unitToNumber(const Unit unit);
	void printUnit(const Unit unit);
	void printProduct();

	Product& operator = (const Product& product);
};
