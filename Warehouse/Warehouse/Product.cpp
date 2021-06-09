#include<cstring>
#include <math.h>   
#include<iostream>

#include "Product.h"
using namespace std;

void Product::setDefaultValues()
{
    description = nullptr;
    manufacturer = nullptr;
    unit = Unknown;
    quantity = 0;
    location = 0;
    comment = nullptr;
}

Product::Product()
{
    setDefaultValues();
}

Product::~Product()
{
    delete[] description;
    delete[] manufacturer;
    delete[] comment;

    setDefaultValues();
}

void Product::setDescription(const char* description) {
    size_t lengthDescription = strlen(description) + 1;
    this->description = new char[lengthDescription];
    strcpy_s(this->description, lengthDescription, description);
}

void Product::setManufacturer(const char* manufacturer) {
    size_t lengthManufacturer = strlen(manufacturer) + 1;
    this->manufacturer = new char[lengthManufacturer];
    strcpy_s(this->manufacturer, lengthManufacturer, manufacturer);
}

void Product::setComment(const char* comment) {
    size_t lengthComment = strlen(comment) + 1;
    this->comment = new char[lengthComment];
    strcpy_s(this->comment, lengthComment, comment);
}

void Product::setQuantity(const int quantity) {
    this->quantity = quantity;
}

void Product::setLocation(const int location) {
    this->location = location;
}

void Product::setExpiryDate(const DateTime& expiryDate) {
    this->expiryDate = expiryDate;
}

void Product::setEntryDate(const DateTime& entryDate) {
    this->entryDate = entryDate;
}

void Product::setExpiryDate(const char* expiryDate) {
   
    this->expiryDate = DateTime(expiryDate);
}

void Product::setEntryDate(const char* entryDate) {
    
    this->entryDate = DateTime(entryDate);
}

bool Product::setUnit(const int unit)
{
    if (unit == 0)
    {
        this->unit = Kilograms;
        return true;
    }
    if (unit == 1)
    {
        this->unit = Liters;
        return true;
    }
    this->unit = Unknown;
    return false;
}

char* Product::getDescription() const { 
    return this->description;
}

char* Product::getManufacturer() const {
    return this->manufacturer;
}

DateTime& Product::getExpiryDate(){
    return this->expiryDate;
}

DateTime& Product::getEntryDate() {
    return this->entryDate;
}

int Product::getQuantity() const {
    return this->quantity;
}

int Product::getLocation() const {
    return this->location;
}

char* Product::getComment() const {
    return this->comment;
}

int Product::unitToNumber(const Unit unit) {
    switch (unit)
    {
      case Kilograms:
        return 0;

      case Liters:
          return 1;

    default:
        return 2;
    }
}

void Product::printUnit(const Unit unit) {
    switch (unit)
    {
    case Kilograms:
        std::cout << "Kilograms" << std::endl;
        break;

    case Liters:
        std::cout << "Liters" << std::endl;
        break;

    default:
        std::cout << "Unknown" << std::endl;
        break;
    }
}

Unit Product::getUnit() const {
    return unit;
}

void Product::printProduct()
{
    cout << "Description : " << this->getDescription() << endl;

    DateTime currDate = this->getExpiryDate();
    cout << "Expiry Date : ";
    cout << currDate.getYear() << '/' << currDate.getMonth() << '/'
        << currDate.getDay() << endl;

    cout << "Entry Date : ";
    currDate = this->getEntryDate();
    cout << currDate.getYear() << '/' << currDate.getMonth() << '/'
        << currDate.getDay() << endl;

    cout << "Manufacturer: ";
    cout << this->getManufacturer() << endl;

    cout << "Unit : ";
    this->printUnit(this->getUnit());

    cout << "Quantity : ";
    cout << this->getQuantity() << endl;

    cout << "Location : ";
    cout << this->getLocation() << endl;
    cout << "Comment : ";
    cout << this->getComment() << endl;
}

Product& Product::operator = (const Product& product) {
    if (this != &product)
    {
        delete[] description;
        delete[] manufacturer;
        delete[] comment;

        setDescription(product.description);
        setManufacturer(product.manufacturer);
        setExpiryDate(product.expiryDate);
        setEntryDate(product.entryDate);
        setQuantity(product.quantity);
        setLocation(product.location);
        setComment(product.comment);
        setUnit(product.unit);
    }
    return *this;
}

bool Product::operator==(const Product& product)
{
    return strcmp(this->getDescription(), product.getDescription()) == 0
        && strcmp(this->getManufacturer(), product.getManufacturer()) == 0
        && strcmp(this->getComment(), product.getComment()) == 0;
}
