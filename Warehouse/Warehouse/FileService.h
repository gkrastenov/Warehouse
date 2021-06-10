#pragma once
#include "List.h"
#include "Product.h"
#include "Change.h"

class FileService
{
private:
	char* fileName;

	void cleanFile(const char* fileName);
	bool isEqual(const char* first, const char* second);
	void withBigQuantityProduct(List<Product>& list, Product& newProduct, int sumQuantity);
	bool contains(int index[], int size, int elem);

public:
	const char LOG_FILENAME[9] = "logs.txt";

	const int MAX_FILENAME = 50;

	List<Product> products;
	List<Change> changes;

	FileService();
	~FileService();

	void setFileName(const char* name);
	char* getFileName() const;

	List<Product> readProductsFromFile(const char* fileName) const;
	List<Change> readChangesFromFile() const;
	bool writeProductsToFile(const char* fileName);
	void writeChangesToFile();
	void writeProductsToFile(int index[], const int size, const char* fileName);

	bool isExistsFile(const char* fileName);
	bool isOpenFile();
	void createFile(const char* fileName);
	void getAllProducts() const;
	void removeProduct(Product& newProduct);
	List<Product> addProduct(Product& newProduct);
	void cleanProducts(const DateTime& dateTime);

	FileService& operator = (const FileService& date);
};