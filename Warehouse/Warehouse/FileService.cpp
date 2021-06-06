#include "FileService.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <chrono>
#include <ctime>  
#include "File.h"

using namespace std;

bool FileService::isOpenFile()
{
	if (this->fileName == nullptr)
	{
		cout << "Please open/create file to work with him" << endl;
		return false;
	}

	return true;
}

FileService::FileService()
{
	this->fileName = nullptr;
}

FileService::~FileService()
{
	delete[] this->fileName;
	this->fileName = nullptr;
}

Vector<Product> FileService::readFromFile(const char* fileName) const
{
	Vector<Product> productsFromFile = Vector<Product>();

	ifstream file(fileName);

	char descriptionLine[50];
	char expiryDateLine[30];
	char entryDateLine[30];
	char manufacturLine[30];
	int unitLine;
	int  qantityLine;
	int  locationLine;
	char commentLine[30];

	while (!file.eof())
	{
		Product currentProduct = Product();

		file >> descriptionLine;

		if (descriptionLine[0] == '\0')
		{
			break;
		}
		currentProduct.setDescription(descriptionLine);

		file >> expiryDateLine;
		currentProduct.setExpiryDate(expiryDateLine);

		file >> entryDateLine;
		currentProduct.setEntryDate(entryDateLine);

		file >> manufacturLine;
		currentProduct.setManufacturer(manufacturLine);

		file >> unitLine;
		currentProduct.setUnit(unitLine);

		file >> qantityLine;
		currentProduct.setQuantity(qantityLine);

		file >> locationLine;
		currentProduct.setLocation(locationLine);

		file >> commentLine;
		currentProduct.setComment(commentLine);

		productsFromFile.push_back(currentProduct);
	}

	file.close();
	return productsFromFile;
}

bool FileService::writeToFile() const
{
	ofstream myfile;

	myfile.open(fileName);
	for (size_t i = 0; i < products.getSize(); i++)
	{
		Product currentProduct = products[i];

		DateTime expiryDate = currentProduct.getExpiryDate();
		DateTime entryDate = currentProduct.getEntryDate();

		// add product to file
		myfile << currentProduct.getDescription()
			<< " " << expiryDate.getYear() << '/' << expiryDate.getMonth() << '/' << expiryDate.getDay()
			<< " " << entryDate.getYear() << '/' << entryDate.getMonth() << '/' << entryDate.getDay()
			<< " " << currentProduct.getManufacturer()
			<< " " << currentProduct.unitToNumber(currentProduct.getUnit())
			<< " " << currentProduct.getQuantity()
			<< " " << currentProduct.getLocation()
			<< " " << currentProduct.getComment() << endl;
	}

	myfile.close();
	return true;
}

bool FileService::isFileExist(const char* fileName)
{
	std::fstream fileStream;
	fileStream.open(fileName);
	if (fileStream.fail()) {
		return false;
	}
	return true;
}

void FileService::createFile(const char* fileName)
{
	ofstream MyFile(fileName);
}

bool FileService::addProduct(const Product& product)
{
	products.push_back(product);
	return true;
}

void FileService::getAllProducts() const
{
	Vector<Product> availableProducts = readFromFile(fileName);

	for (size_t i = 0; i < availableProducts.getSize(); i++)
	{
		cout << "--------------- [" << i + 1<< "]--------------" << endl;
		cout << "Description: " << availableProducts[i].getDescription() << endl;
		cout << "EntryDate: " << availableProducts[i].getEntryDate() << endl;
		cout << "ExpiryDate: " << availableProducts[i].getExpiryDate() << endl;
		cout << "Manufacturer: " << availableProducts[i].getManufacturer() << endl;
		cout << "Unit: ";
		availableProducts[i].printUnit(availableProducts[i].getUnit());
		cout << endl;
		cout << "Quantity: " << availableProducts[i].getQuantity() << endl;
		cout << "Location: " << availableProducts[i].getLocation() << endl;
		cout << "Comment: " << availableProducts[i].getComment() << endl;
	}
	;
}

char* FileService::getFileName() const 
{
	return this->fileName;
}

void FileService::setFileName(const char* name)
{
	size_t lengthName = strlen(name) + 1;
	this->fileName = new char[lengthName];
	strcpy_s(this->fileName, lengthName, name);
}

FileService& FileService::operator=(const FileService& fileService)
{
	if (this != &fileService)
	{
		this->products = fileService.products;
	}

	return *this;
}