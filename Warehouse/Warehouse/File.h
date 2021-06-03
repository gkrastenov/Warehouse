#pragma once
#include "Product.h"

class File
{
private:
	char* fileName;
	bool isOpen;
	bool isCreated;

	Product* products;
	int count;
	int capacity;

	char* enterString(const size_t length);
	void write(const char* fileName);
	void read();
	bool isExists(const char* fileName);
public:
	File();
	~File();

	void initialCreate();
	bool add();
	void removeProduct(const size_t index);
	bool print();
	bool exit();
	bool help();
	bool saveAs();
	bool clean();

	void setFileName(const char* name);
	char* getFileName();
};

