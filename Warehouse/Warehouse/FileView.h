#pragma once
#include "FileService.h"
#include "DateTime.h"
#include "Product.h"

class FileView
{
private:
	FileService service;

	char* enterString(const size_t length);
	bool isValidEnterDate(const DateTime& dateTime);
	bool isValidEnterDescription(const Product& enterProduct);
	bool isValidEnterManufacturer(const Product& enterProduct);
	bool isValidEnterComment(const Product& enterProduct);
	bool isValidEnterLocation(const Product& enterProduct);
	bool isValidEnterQuantity(const Product& enterProduct);

public:
	FileView();

	bool openView();
	bool closeView();
	bool saveView();
	bool saveAsView();
	bool helpView();
	bool exitView();
	bool addView();
	bool printView();
	bool cleanView();
};