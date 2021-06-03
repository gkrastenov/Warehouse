#pragma once
#include "Vector.h"
#include "Product.h"

class FileService
{
private:
	char* fileName;

public:
	const size_t MAX_SIZE_FILENAME = 50;

	Vector<Product> products;

	FileService();
	~FileService();

	void setFileName(const char* name);
	char* getFileName() const;

     //Vector<Product>& ReadFromFile(const char* fileName) const;
	bool WriteToFile() const;

	bool isFileExist(const char* fileName);
	bool IsOpenFile();
	void createFile(const char* fileName);
	bool addProduct(const Product& newProduct);

	FileService& operator = (const FileService& date);
};
