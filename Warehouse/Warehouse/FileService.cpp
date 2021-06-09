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

List<Product> FileService::readFromFile(const char* fileName) const
{
	List<Product> productsFromFile;

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
		Product currentProduct;

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

		productsFromFile.add(currentProduct);
	}

	file.close();
	return productsFromFile;
}

bool FileService::writeToFile(const char* fileName)
{
	cleanFile();

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

void FileService::writeToFile(int index[], const int size, const char* fileName)
{
	cleanFile();

	ofstream myfile;
	myfile.open(fileName);

	for (size_t i = 0; i < products.getSize(); i++)
	{
		if (contains(index, size, i))
		{
			// TODO : print info for product
			continue;
		}
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
}

void FileService::cleanFile() const
{
	ofstream ofs;
	ofs.open(fileName, std::ofstream::trunc);
	ofs.close();
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

void FileService::getAllProducts() const
{
	List<Product> availableProducts = readFromFile(fileName);

	for (size_t i = 0; i < availableProducts.getSize(); i++)
	{
		cout << "--------------- [" << i + 1<< "]--------------" << endl;
		cout << "Description: " << availableProducts[i].getDescription() << endl;
		cout << "EntryDate: " << availableProducts[i].getEntryDate() << endl;
		cout << "ExpiryDate: " << availableProducts[i].getExpiryDate() << endl;
		cout << "Manufacturer: " << availableProducts[i].getManufacturer() << endl;
		cout << "Unit: ";
		availableProducts[i].printUnit(availableProducts[i].getUnit());
		cout << "Quantity: " << availableProducts[i].getQuantity() << endl;
		cout << "Location: " << availableProducts[i].getLocation() << endl;
		cout << "Comment: " << availableProducts[i].getComment() << endl;
	}
}

void FileService::addProduct(Product& newProduct)
{
	for (size_t i = 0; i < products.getSize(); i++)
	{
		// first requirement
		if (isEqual(products[i].getDescription(), newProduct.getDescription()) 
		    && products[i].getExpiryDate() != newProduct.getExpiryDate())
		{
			if (products[i].getLocation() != newProduct.getLocation())
			{
				withBigQuantityProduct(newProduct, newProduct.getQuantity());
				return;
			}
			else {

				int newLocation = newProduct.getLocation();
				while (newLocation == products[i].getLocation())
				{
					std::cout << "Enter new location because this product: " << newProduct.getDescription() << " has equal expiry date" << endl;
					cin >> newLocation;
				}

				newProduct.setLocation(newLocation);
				withBigQuantityProduct(newProduct, newProduct.getQuantity());
				return;
			}
		}

		// second requirement
		if (isEqual(products[i].getDescription(), newProduct.getDescription())
			&& products[i].getExpiryDate() == newProduct.getExpiryDate()
			&& products[i].getQuantity() < newProduct.MAX_QUANTITY)
		{
			int sumQuantity = products[i].getQuantity() + newProduct.getQuantity();
			if (sumQuantity <= 10)
			{
				products[i].setQuantity(sumQuantity);
				return;
			}
			else {
				products[i].setQuantity(newProduct.MAX_QUANTITY);

				if (newProduct.getLocation() == products[i].getLocation())
				{
					int newLocation;
					std::cout << "Enter new location because this product: " << newProduct.getLocation() << " is full" << endl;
					cin >> newLocation;
					newProduct.setLocation(newLocation);
				}

				withBigQuantityProduct(newProduct, sumQuantity - 10);
				return;
			}
		}
	}

	int sumQuantity = newProduct.getQuantity();
	withBigQuantityProduct(newProduct, sumQuantity);
}

void FileService::cleanProducts(const DateTime& dateTime)
{
	int index[20];
	int size = 0;

	for (size_t i = 0; i < this->products.getSize(); i++)
	{
		if (products[i].getExpiryDate() <= dateTime)
		{
			index[size] = i;
			size++;
		}
	}

    writeToFile(index, size, this->fileName);

	List<Product> test = readFromFile(this->fileName);
	products.copy(test);

	std::cout << "Cleaned successfully" << endl;
}

void FileService::withBigQuantityProduct(Product& newProduct, int sumQuantity)
{
	if (sumQuantity > newProduct.MAX_QUANTITY)
	{
		while (sumQuantity > 0)
		{
			if (sumQuantity <= newProduct.MAX_QUANTITY)
			{
				newProduct.setQuantity(sumQuantity);
				products.add(newProduct);
				sumQuantity -= newProduct.MAX_QUANTITY;
			}
			else {
				newProduct.setQuantity(newProduct.MAX_QUANTITY);
				products.add(newProduct);
				sumQuantity -= newProduct.MAX_QUANTITY;
			}
		}
	}
	else {
		newProduct.setQuantity(sumQuantity);
		products.add(newProduct);
		return;
	}
}

bool FileService::contains(int index[], int size, int elem)
{
	for (size_t i = 0; i < size; i++)
	{
		if (index[i] == elem)
		{
			return true;
		}
	}

	return false;
}

bool FileService::isEqual(const char* first, const char* second)
{
	return strcmp(first, second) == 0;
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