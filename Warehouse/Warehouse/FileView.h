#pragma once
#include "FileService.h"
#include "DateTime.h"
#include "Product.h"

class FileView
{
private:
	FileService service;

	char* enterString(const size_t length);

public:
	FileView();

	bool openView();
	bool closeView();
	bool saveView();
	bool saveAsView();
	bool helpView();
	bool exitView();
	bool addView();
	bool removeView();
	bool printView();
	bool cleanView();
	bool logView();

	bool isValidEnterDate(const DateTime& dateTime) const;
	bool isValidEnterDescription(const Product& enterProduct) const;
	bool isValidEnterManufacturer(const Product& enterProduct) const;
	bool isValidEnterComment(const Product& enterProduct) const;
	bool isValidEnterLocation(const Product& enterProduct) const;
	bool isValidEnterQuantity(const Product& enterProduct) const;
	bool isValidEnterFileName(const char* fileName) const;
};