#include<cstring>
#include <math.h>   
#include<iostream>

#include "Product.h"
using namespace std;

void Product::setDefaultValues()
{
    manufacturer = nullptr;
    unit = Unit::Unknown;
    location = 0;
    comment = nullptr;
}

Product::Product()
{
    setDefaultValues();
}

Product::~Product()
{
    delete[] manufacturer;
    delete[] comment;

    setDefaultValues();
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

void Product::setLocation(const int location) {
    this->location = location;
}

void Product::setExpiryDate(const DateTime& expiryDate) {
    this->expiryDate = expiryDate;
}

void Product::setExpiryDate(const char* expiryDate) {
   
    this->expiryDate = DateTime(expiryDate);
}

void Product::setUnit(const Unit unit)
{
    this->unit = unit;
}
bool Product::setUnit(const int unit)
{
    if (unit == 0)
    {
        this->unit = Unit::Kilograms;
        return true;
    }
    if (unit == 1)
    {
        this->unit = Unit::Liters;
        return true;
    }

    this->unit = Unit::Unknown;
    return false;
}

char* Product::getManufacturer() const {
    return this->manufacturer;
}

DateTime& Product::getExpiryDate(){
    return this->expiryDate;
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
    case Unit::Kilograms:
        return 0;

      case Unit::Liters:
          return 1;

    default:
        return 2;
    }
}

void Product::printUnit(const Unit unit) {
    switch (unit)
    {
    case Unit::Kilograms:
        std::cout << "Kilograms" << std::endl;
        break;

    case Unit::Liters:
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

void Product::print()
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
        delete[] manufacturer;
        delete[] comment;

        setManufacturer(product.manufacturer);
        setExpiryDate(product.expiryDate);
        setEntryDate(product.entryDate);
        setQuantity(product.quantity);
        setLocation(product.location);
        setComment(product.comment);
        setUnit(product.getUnit());
    }
    return *this;
}

bool Product::operator==(const Product& product)
{
    return strcmp(this->getDescription(), product.getDescription()) == 0
        && strcmp(this->getManufacturer(), product.getManufacturer()) == 0
        && strcmp(this->getComment(), product.getComment()) == 0;
}
