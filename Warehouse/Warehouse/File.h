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

	void write(const char* fileName);
	void read();
	bool isExists(const char* fileName);
public:
	File();
	~File();

	void initialCreate();
	void removeProduct(const size_t index);
	bool print();
	bool exit();
	bool saveAs();
	bool clean();

	void setFileName(const char* name);
	char* getFileName();
};

