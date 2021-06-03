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

bool FileService::IsOpenFile()
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

bool FileService::WriteToFile() const
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