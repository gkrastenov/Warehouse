#pragma once
#include "Vector.h"
#include "Product.h"

class FileService
{
private:
	char* fileName;

	void cleanFile() const;
	bool isEqual(const char* first, const char* second);
	void withBigQuantityProduct(Product& newProduct, int sumQuantity);

public:
	const size_t MAX_SIZE_FILENAME = 50;
	const int MAX_SIZE_QUANTITY= 10;


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
	void getAllProducts() const;
	void addProduct(Product& newProduct);

	FileService& operator = (const FileService& date);
};