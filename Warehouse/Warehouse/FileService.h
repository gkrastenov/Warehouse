#pragma once
#include "List.h"
#include "Product.h"

class FileService
{
private:
	char* fileName;

	void cleanFile() const;
	bool isEqual(const char* first, const char* second);
	void withBigQuantityProduct(Product& newProduct, int sumQuantity);
	bool contains(int index[], int size, int elem);

public:
	const int MAX_FILENAME = 50;

	List<Product> products;

	FileService();
	~FileService();

	void setFileName(const char* name);
	char* getFileName() const;

	List<Product> readFromFile(const char* fileName) const;
	bool writeToFile(const char* fileName);
	void writeToFile(int index[], const int size,const char* fileName);

	bool isFileExist(const char* fileName);
	bool isOpenFile();
	void createFile(const char* fileName);
	void getAllProducts() const;
	void removeProduct(Product& newProduct);
	void addProduct(Product& newProduct);
	void cleanProducts(const DateTime& dateTime);

	FileService& operator = (const FileService& date);
};