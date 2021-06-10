#include "FileService.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <chrono>
#include <ctime>  

// for getting date now
#pragma warning(disable : 4996)
using namespace std;

bool FileService::isOpenFile()
{
	if (this->fileName == nullptr || strcmp(this->fileName, "") == 0)
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

List<Product> FileService::readProductsFromFile(const char* fileName) const
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

List<Change> FileService::readChangesFromFile() const
{
	List<Change> changesFromFile;

	ifstream file(LOG_FILENAME);

	char descriptionLine[50];
	char entryDateLine[30];
	int changeTypeLine;
	int  qantityLine;

	while (!file.eof())
	{
		Change currentChange;

		file >> entryDateLine;

		if (entryDateLine[0] == '\0')
		{
			break;
		}
		currentChange.setEntryDate(entryDateLine);

		file >> changeTypeLine;
		currentChange.setChangeType(changeTypeLine);

		file >> descriptionLine;
		currentChange.setDescription(descriptionLine);

		file >> qantityLine;
		currentChange.setQuantity(qantityLine);

		changesFromFile.add(currentChange);
	}

	file.close();
	return changesFromFile;
}

bool FileService::writeProductsToFile(const char* fileName)
{
	cleanFile(fileName);

	ofstream myfile;
	myfile.open(fileName);

	for (size_t i = 0; i < products.getSize(); i++)
	{

		Product currentProduct(products[i]);

		if (currentProduct.getQuantity() == 0)
		{
			cout << "Has been removed product " << currentProduct.getDescription()
				 << " with quntity "<< currentProduct.getQuantity()
				 << " in location " << currentProduct.getLocation() << endl;

			continue;
		}

		DateTime expiryDate = currentProduct.getExpiryDate();
		DateTime entryDate = currentProduct.getEntryDate();

		// add product to file
		myfile << currentProduct.getDescription()
			<< " " << expiryDate
			<< " " << entryDate
			<< " " << currentProduct.getManufacturer()
			<< " " << currentProduct.unitToNumber(currentProduct.getUnit())
			<< " " << currentProduct.getQuantity()
			<< " " << currentProduct.getLocation()
			<< " " << currentProduct.getComment() << endl;
	}

	myfile.close();
	return true;
}

void FileService::writeChangesToFile()
{
	cleanFile(LOG_FILENAME);

	ofstream myfile;
	myfile.open(LOG_FILENAME);

	for (size_t i = 0; i < changes.getSize(); i++)
	{
		// add change to file
		DateTime entryDate = changes[i].getEntryDate();

		myfile << entryDate
			<< " " << changes[i].changeTypeToInt(changes[i].getChangeType())
			<< " " << changes[i].getDescription()
			<< " " << changes[i].getQuantity() << endl;
	}

	myfile.close();
}

void FileService::writeProductsToFile(int index[], const int size, const char* fileName)
{
	cleanFile(fileName);

	ofstream myfile;
	myfile.open(fileName);

	for (size_t i = 0; i < products.getSize(); i++)
	{
		Product currentProduct(products[i]);
		if (contains(index, size, i))
		{
			cout << "It has been cleaned product: " << endl;
			currentProduct.print();

			// get time now
			std::time_t time = std::time(0);
			std::tm* now = std::localtime(&time);
			DateTime dateNow = DateTime((now->tm_year + 1900), (now->tm_mon + 1), now->tm_mday);

			Change newChange = Change(currentProduct.getDescription(), currentProduct.getQuantity(), dateNow, ChangeType::Clean);
			changes.add(newChange);

			continue;
		}

		DateTime expiryDate = currentProduct.getExpiryDate();
		DateTime entryDate = currentProduct.getEntryDate();

		// add product to file
		myfile << currentProduct.getDescription()
			<< " " << expiryDate
			<< " " << entryDate
			<< " " << currentProduct.getManufacturer()
			<< " " << currentProduct.unitToNumber(currentProduct.getUnit())
			<< " " << currentProduct.getQuantity()
			<< " " << currentProduct.getLocation()
			<< " " << currentProduct.getComment() << endl;
	}

	myfile.close();
}

void FileService::cleanFile(const char* fileName)
{
	ofstream ofs;
	ofs.open(fileName, std::ofstream::trunc);
	ofs.close();
}

bool FileService::isExistsFile(const char* fileName)
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
	List<Product> availableProducts = readProductsFromFile(fileName);

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

void FileService::removeProduct(Product& newProduct)
{
	List<int> indexs;
	for (size_t i = 0; i < products.getSize(); i++)
	{
		if (products[i].getDescription() == newProduct.getDescription())
		{
			indexs.add(i);
		}
	}

	if (indexs.getSize() <= 0)
	{
		return;
	}

	// remove second requirement 
	int productWithLessExpiryDateIndex = indexs[0];

	for (size_t i = 0; i < products.getSize(); i++)
	{
		if (indexs.contains(i))
		{
			if (products[i].getExpiryDate() <= products[productWithLessExpiryDateIndex].getExpiryDate())
			{
				productWithLessExpiryDateIndex = i;
			}
		}
	}

	// remove third requirement 
	if (products[productWithLessExpiryDateIndex].getQuantity() < newProduct.getQuantity())
	{
		cout << "This product is a smaller quantity " << endl;
		cout << "Description: " << products[productWithLessExpiryDateIndex].getDescription() << endl;;
		cout << "Quantity: " << products[productWithLessExpiryDateIndex].getQuantity() << endl;
		cout << "ExpiryDate: " << products[productWithLessExpiryDateIndex].getExpiryDate() << endl;

		cout << "Enter true to be removed all quantity and false to be skipped (true/false)" << endl;
		char command[20];
		cin >> command;
		if (strcmp(command, "true") == 0)
		{
			products[productWithLessExpiryDateIndex].setQuantity(0);
		}
	}
	else {
		int newQuantity = products[productWithLessExpiryDateIndex].getQuantity() - newProduct.getQuantity();
		products[productWithLessExpiryDateIndex].setQuantity(newQuantity);
	}

	// get time now
	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);
	DateTime dateNow = DateTime((now->tm_year + 1900), (now->tm_mon + 1), now->tm_mday);

	Change newChange = Change(newProduct.getDescription(), newProduct.getQuantity(), dateNow, ChangeType::Remove);
	changes.add(newChange);
}


List<Product> FileService::addProduct(Product& newProduct)
{
	List<Product> list(products);

	for (size_t i = 0; i < products.getSize(); i++)
	{
		// first requirement
		if (products[i].getDescription() ==  newProduct.getDescription() 
		    && products[i].getExpiryDate() != newProduct.getExpiryDate())
		{
			if (products[i].getLocation() != newProduct.getLocation())
			{
				withBigQuantityProduct(list, newProduct, newProduct.getQuantity());
				return list;
			}
			else {

				int newLocation = newProduct.getLocation();
				while (newLocation == products[i].getLocation())
				{
					std::cout << "Enter new location because this product: " << newProduct.getDescription() << " has equal expiry date" << endl;
					cin >> newLocation;
				}

				newProduct.setLocation(newLocation);
				withBigQuantityProduct(list, newProduct, newProduct.getQuantity());
				return list;
			}
		}

		// second requirement
		if (products[i].getDescription() == newProduct.getDescription()
			&& products[i].getExpiryDate() == newProduct.getExpiryDate()
			&& products[i].getQuantity() < newProduct.MAX_QUANTITY)
		{
			int sumQuantity = products[i].getQuantity() + newProduct.getQuantity();
			if (sumQuantity <= 10)
			{
				products[i].setQuantity(sumQuantity);
				return list;
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

				withBigQuantityProduct(list, newProduct, sumQuantity - 10);
				return list;
			}
		}
	}

	int sumQuantity = newProduct.getQuantity();
	withBigQuantityProduct(list, newProduct, sumQuantity);

	// get time now
	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);
	DateTime dateNow = DateTime((now->tm_year + 1900), (now->tm_mon + 1), now->tm_mday);

	Change newChange = Change(newProduct.getDescription(), newProduct.getQuantity(), dateNow, ChangeType::Add);
	changes.add(newChange);

	return list;
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

    writeProductsToFile(index, size, this->fileName);
	products.copy(readProductsFromFile(this->fileName));

	std::cout << "Cleaned successfully" << endl;
}

void FileService::withBigQuantityProduct(List<Product>& list, Product& newProduct, int sumQuantity)
{
	if (sumQuantity > newProduct.MAX_QUANTITY)
	{
		while (sumQuantity > 0)
		{
			if (sumQuantity <= newProduct.MAX_QUANTITY)
			{
				newProduct.setQuantity(sumQuantity);
				list.add(newProduct);
				sumQuantity -= newProduct.MAX_QUANTITY;
			}
			else {
				newProduct.setQuantity(newProduct.MAX_QUANTITY);
				list.add(newProduct);
				sumQuantity -= newProduct.MAX_QUANTITY;
			}
		}
	}
	else {
		newProduct.setQuantity(sumQuantity);
		list.add(newProduct);
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