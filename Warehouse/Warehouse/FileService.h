#pragma once
#include "Vector.h"
#include "Product.h"

class FileService
{
private:
	char* fileName;

	void cleanFile() const;

public:
	const size_t MAX_SIZE_FILENAME = 50;

	Vector<Product> products;

	FileService();
	~FileService();

	void setFileName(const char* name);
	char* getFileName() const;

	Vector<Product> readFromFile(const char* fileName) const;
	bool writeToFile() const;

	bool isFileExist(const char* fileName);
	bool isOpenFile();
	void createFile(const char* fileName);
	bool addProduct(const Product& newProduct);
	void getAllProducts() const;

	FileService& operator = (const FileService& date);
};