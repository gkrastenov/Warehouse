#include "FileView.h"
#include<iostream>

using namespace std;

FileView::FileView() {
	this->service = FileService();
}

bool FileView::openView() {
	cout << "Enter file name (Example: file2.txt)" << endl;

	char inputFileName[50];
	cin.getline(inputFileName, 50);
	
	this->service.setFileName(inputFileName);

	if (service.isFileExist(inputFileName))
	{
		service.products = service.readFromFile(inputFileName);
		cout << "Successfully opened " << inputFileName << endl;
		return true;
	}

	// create
	service.createFile(inputFileName);
	cout << "File it was not exists but now succesfully is created and opened " << inputFileName << endl;

	return true;
}

bool FileView::closeView()
{

	if (this->service.isOpenFile() == false)
	{
		return true;
	}

	this->service.setFileName(nullptr);
	this->service.products = Vector<Product>();

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

	bool isSaved = this->service.writeToFile();
	if (isSaved)
	{
		cout << "Saved succesfully" << endl;
		return true;
	}

	cout << "Save failed" << endl;
	return false;
}

bool FileView::saveAsView() {
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

	Product product = Product();
	cout << "Enter product description" << endl;
	product.setDescription(enterString(product.MAX_DESCRIPTION_LENGTH));

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
	product.setManufacturer(enterString(product.MAX_MANUFACTURER_LENGTH));

	cout << "Enter product comment" << endl;
	product.setComment(enterString(product.MAX_COMMENT_LENGTH));

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

	return this->service.addProduct(product);
}

char* FileView::enterString(const size_t length)
{
	char* str = new char[length + 1];
	std::cin.getline(str, length + 1);
	return str;
}

bool FileView::isValidEnterDate(const DateTime& dateTime)
{
	return (dateTime.getDay() == 0 || dateTime.getMonth() == 0 || dateTime.getYear() == 0) == false;
}

bool FileView :: printView()
{
	if (this->service.isOpenFile() == false)
	{
		return true;
	}

	this->service.getAllProducts();
	return true;
}