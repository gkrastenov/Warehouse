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
	const int MAX_FILENAME = 50;

	const int MIN_DESCRIPTION = 2;
	const int MAX_DESCRIPTION = 50;

	const int MIN_MANUFACTURER= 5;
	const int MAX_MANUFACTURER = 50;

	const int MIN_QUANTITY = 1;
	const int MAX_QUANTITY = 10;

	const int MIN_LOCATION= 1;
	const int MAX_LOCATION = 100;

	const int MIN_COMMENT= 2;
	const int MAX_COMMENT = 200;

	List<Product> products;

	FileService();
	~FileService();

	void setFileName(const char* name);
	char* getFileName() const;

	List<Product> readFromFile(const char* fileName) const;
	bool writeToFile() const;

	bool isFileExist(const char* fileName);
	bool isOpenFile();
	void createFile(const char* fileName);
	void getAllProducts() const;
	void addProduct(Product& newProduct);

	FileService& operator = (const FileService& date);
};