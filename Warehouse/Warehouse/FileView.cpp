#include "FileView.h"
#include<iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <chrono>
#include <ctime>  

// for getting date now
#pragma warning(disable : 4996)
using namespace std;

FileView::FileView() {
	this->service = FileService();
}

bool FileView::openView() {
	cout << "Enter file name (Example: file2.txt)" << endl;

	char inputFileName[50];
	cin >> inputFileName;
	cin.ignore();

	this->service.setFileName(inputFileName);

	if (service.isExistsFile(inputFileName))
	{
		service.products = service.readProductsFromFile(inputFileName);
		service.changes = service.readChangesFromFile();

		cout << "Successfully opened " << inputFileName << endl;
		return true;
	}

	// create
	service.createFile(inputFileName);
	cout << "File it was not exists but now succesfully is created and opened " << inputFileName << endl;

	service.changes = service.readChangesFromFile();
	return true;
}

bool FileView::closeView()
{
	if (this->service.isOpenFile() == false)
	{
		return true;
	}
	
	List<Product> emptyList;
	service.products.copy(emptyList);
	service.setFileName("");
	cout << "Closed successfully" << endl;
	return true;
}

bool FileView::saveView() 
{
	if (this->service.isOpenFile() == false)
	{
		return true;
	}

	cout << "Saving......" << endl;

	this->service.writeChangesToFile();

	bool isSaved = this->service.writeProductsToFile(this->service.getFileName());
	if (isSaved)
	{
		cout << "Saved succesfully" << endl;
		return true;
	}

	cout << "Save failed" << endl;
	return false;
}

bool FileView::saveAsView() {
	if (this->service.isOpenFile() == false)
	{
		return true;
	}

	cout << "Enter file name (Example: other.txt)" << endl;

	char inputFileName[50];
	cin.getline(inputFileName, 50);

	if (this->service.isExistsFile(inputFileName))
	{
		cout << "File with this name: " << inputFileName << " already exists, please enter another file name" << endl;
		return true;
	}

	service.createFile(inputFileName);
	
	bool isSaved = this->service.saveAsProducts(inputFileName);
	if (isSaved)
	{
		cout << "Saved As succesfully" << endl;
		return true;
	}

	cout << "Save As failed" << endl;
	return true;
}

bool FileView::helpView() {

	cout << endl;
	cout << "Coomand open: open the given file  " << endl;
	cout << "Command cloe: close the given file" << endl;
	cout << "Command save: save the given file" << endl;
	cout << "Command saveAs: saveAs the given file" << endl;

	return true;
}

bool FileView::exitView()
{
	cout << "Exit successfully." << endl;
	return false;
}

bool FileView::addView() {

	if (this->service.isOpenFile() == false)
	{
		return false;
	}

	Product product;

	cout << "Enter product description" << endl;
	char descrp[50];
	cin >> descrp;
	cin.ignore();
	String description(descrp);
	product.setDescription(description);

	cout << "Enter expiry date time (example: 2021/12/23)" << endl;
	product.setExpiryDate(enterString(10));

	cout << "Enter entry date time (example: 2020/12/23)" << endl;
	product.setEntryDate(enterString(10));

	if (isValidEnterDate(product.getEntryDate()) == false 
		|| isValidEnterDate(product.getExpiryDate()) == false
		|| product.getEntryDate() < product.getExpiryDate() == false)
	{
		return false;
	}

	cout << "Enter product manufacturer" << endl;
	char manufact[50];
	cin >> manufact;
	String manufacturer(manufact);
	product.setManufacturer(manufacturer);

	cout << "Enter product comment" << endl;
	char comm[50];
	cin >> comm;
	String comment(comm);
	product.setComment(comment);

	cout << "Enter product unit (0 for Kilograms , 1 for Liters)" << endl;
	int unit;
	cin >> unit;
	product.setUnit(unit);

	cout << "Enter quantity:" << endl;
	int quantity;
	cin >> quantity;
	product.setQuantity(quantity);

	cout << "Enter location:" << endl;
	int location;
	cin >> location;
	product.setLocation(location);

	if (isValidEnterDescription(product) == false
		|| isValidEnterManufacturer(product) == false
		|| isValidEnterComment(product) == false
		|| isValidEnterLocation(product) == false
		|| isValidEnterQuantity(product) == false)
	{
		return false;
	}
	else {
		this->service.products.copy(this->service.addProduct(product));
		return true;
	}
}

bool FileView::removeView()
{
	if (this->service.isOpenFile() == false)
	{
		return true;
	}

	Product product = Product();

	cout << "Enter product description" << endl;
	char descrp[50];
	cin >> descrp;
	cin.ignore();
	String description(descrp);
	product.setDescription(description);

	cout << "Enter quantity:" << endl;
	int quantity;
	cin >> quantity;
	product.setQuantity(quantity);

	if (isValidEnterDescription(product) == false
		|| isValidEnterQuantity(product) == false)
	{
		return false;
	}
	
	this->service.removeProduct(product);
	return true;
}

bool FileView::printView()
{
	if (this->service.isOpenFile() == false)
	{
		return true;
	}

	this->service.getAllProducts();
	return true;
}

bool FileView::cleanView()
{
	if (this->service.isOpenFile() == false)
	{
		return true;
	}

	cout << "Cleanning..... " << endl;

	std::time_t time = std::time(0);   // get time now
	std::tm* now = std::localtime(&time);
	DateTime dateNow = DateTime((now->tm_year + 1900), (now->tm_mon + 1), now->tm_mday);

	this->service.cleanProducts(dateNow);
	this->service.writeChangesToFile();

	return true;
}

bool FileView::logView()
{
	cout << "Enter from date time (example: 2019/12/23)" << endl;
	DateTime fromDate(enterString(10));

	cout << "Enter to date time (example: 2020/12/23)" << endl;
	DateTime toDate(enterString(10));

	if (isValidEnterDate(fromDate) == false
		|| isValidEnterDate(toDate) == false
		|| fromDate < toDate == false)
	{
		return false;
	}

	// TODO: read from logs.txt
	return true;
}

char* FileView::enterString(const size_t length)
{
	char* str = new char[length + 1];
	std::cin.getline(str, length + 1);
	return str;
}

bool FileView::isValidEnterDate(const DateTime& dateTime)
{
	return (dateTime.getDay() != 0 || dateTime.getMonth() != 0 || dateTime.getYear() != 0);
}

bool FileView::isValidEnterDescription(const Product& enterProduct)
{
	int length = enterProduct.getDescription().getLength();
	return (length >= enterProduct.MIN_DESCRIPTION && length <= enterProduct.MAX_DESCRIPTION);
}

bool FileView::isValidEnterManufacturer(const Product& enterProduct)
{
	int length = enterProduct.getManufacturer().getLength();
	return (length >= enterProduct.MIN_MANUFACTURER && length <= enterProduct.MAX_MANUFACTURER);
}

bool FileView::isValidEnterComment(const Product& enterProduct)
{
	int length = enterProduct.getComment().getLength();
	return (length >= enterProduct.MIN_COMMENT && length <= enterProduct.MAX_COMMENT);
}

bool FileView::isValidEnterLocation(const Product& enterProduct)
{
	int enterLocation = enterProduct.getLocation();
	return (enterLocation >= enterProduct.MIN_LOCATION && enterLocation <= enterProduct.MAX_LOCATION);
}

bool FileView::isValidEnterQuantity(const Product& enterProduct)
{
	int enterQuantity = enterProduct.getQuantity();
	return (enterQuantity >= enterProduct.MIN_QUANTITY);
}