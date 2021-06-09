#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <chrono>
#include <ctime>  
#include "File.h"

#pragma warning(disable : 4996)

using namespace std;

File::File()
{
	fileName = nullptr;
	isOpen = false;
	isCreated = false;;
    products = nullptr;
	count = 0;
	capacity = 4;
	products = new Product[capacity];

	initialCreate();
}

File::~File()
{
	delete[] fileName;
	delete[] products;

	fileName = nullptr;
	isOpen = false;
	isCreated = false;;
	products = nullptr;
	count = 0;
	capacity = 0;
}


void File::initialCreate()
{
	ofstream MyFile("warehouse.txt");
	setFileName("warehouse.txt");
}

char* File::getFileName() {
	return this->fileName;
}

void File::setFileName(const char* name) {
	size_t lengthName = strlen(name) + 1;
	this->fileName = new char[lengthName];
	strcpy_s(this->fileName, lengthName, name);
}

void File::write(const char* fileName) {

	ofstream myfile;
	myfile.open(fileName);
	for (size_t i = 0; i < count; i++)
	{
		myfile << products[i].getDescription() <<  endl;

		DateTime currDate = products[i].getExpiryDate();
		myfile << currDate.getYear() << '/' << currDate.getMonth() << '/'
			<< currDate.getDay() << endl;

		currDate = products[i].getEntryDate();
		myfile << currDate.getYear() << '/' << currDate.getMonth() << '/'
			<< currDate.getDay() << endl;

		myfile << products[i].getManufacturer() << endl;
		myfile << products[i].unitToNumber(products[i].getUnit()) << endl;
		myfile << products[i].getQuantity() << endl;
		myfile << products[i].getLocation() << endl;
		myfile << products[i].getComment() << endl;
	}
	
	myfile.close();
}

void File::read()
{
	string line;
	ifstream myfile("warehouse.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
}

bool File::print()
{
	for (size_t i = 0; i < count; i++)
	{
		cout << endl;
		cout << "product " << i << endl;
		products[i].printProduct();
	}

	return true;
}

bool File::isExists(const char* fileName)
{
	fstream fileStream;
	fileStream.open(fileName);
	if (fileStream.fail()) {
		return false;
	}
	return true;
}

bool File::saveAs()
{
	cout << "Enter new file name: (Example: other.txt)" << endl;
	// TODO: check for correct file name
	char name[20];
	cin.getline(name, 20);

	if (isExists(name))
	{
		cout << "Exists file with this name:" << name << endl;
		return false;
	}
	
	ofstream MyFile(name);
	write(name);

	return true;
}

bool File::clean()
{
	std::time_t time = std::time(0);   // get time now
	std::tm* now = std::localtime(&time);
	DateTime dateNow = DateTime((now->tm_year + 1900), (now->tm_mon + 1), now->tm_mday);

	cout << "Cleanning: " << endl;
	int index = 0;
	while (index<count)
	{
		if (products[index].getExpiryDate() < dateNow)
		{
			cout << "Product: " << endl;
			products[index].printProduct();
			removeProduct(index);
		}
		index++;
	}

	write(fileName);
	return true;
}

void File::removeProduct(const size_t index)
{
	count--;
	for (size_t i = index; i < count; i++)
	{
		products[i] = products[i + 1];
	}
}