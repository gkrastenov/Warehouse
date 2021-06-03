#include<cstring>
#include <math.h>   
#include<iostream>

#include "Product.h"
using namespace std;

Product::Product()
{
    description = nullptr;
    manufacturer = nullptr;
    unit = Unknown;
    quantity = 0;
    location = 0;
    comment = nullptr;
}

Product::~Product()
{
    delete[] description;
    delete[] manufacturer;
    delete[] comment;

    description = nullptr;
    manufacturer = nullptr;
    unit = Unknown;
    quantity = 0;
    location = 0;
    comment = nullptr;
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

bool Product::setExpiryDate(const char* expiryDate) {
    int date[3] = { 0, 0, 0};
    int index = 0;
    int arrayIndex = 0;
    int curretNumber = 0;
    while (expiryDate[arrayIndex] != '\0')
    {
        if (expiryDate[arrayIndex] == '/')
        {
            arrayIndex++;
            continue;
        }

        if (index == 0)
        {
            // set year
            for (size_t i = 4; i > 0; i--)
            {
                if (isNumber(expiryDate[arrayIndex]))
                {
                    curretNumber += (int)pow(10, i-1) * charToInt(expiryDate[arrayIndex]);
                    arrayIndex++;
                }
                else {
                    return false;
                }
            }
            date[index] = curretNumber;
            curretNumber = 0;
            index++;
        }
        else {

            for (size_t i = 2; i > 0; i--)
            {
                if (isNumber(expiryDate[arrayIndex]))
                {
                    curretNumber += (int)pow(10, i - 1) * charToInt(expiryDate[arrayIndex]);
                    arrayIndex++;
                }
                else {
                    return false;
                }
            }
            date[index] = curretNumber;
            curretNumber = 0;
            index++;
        }
    }
    this->expiryDate = DateTime(date[0], date[1], date[2]);
    return true;
}

bool Product::setEntryDate(const char* entryDate) {
    int date[3] = { 0, 0, 0 };
    int index = 0;
    int arrayIndex = 0;
    int curretNumber = 0;
    while (entryDate[arrayIndex] != '\0')
    {
        if (entryDate[arrayIndex] == '/')
        {
            arrayIndex++;
            continue;
        }

        if (index == 0)
        {
            // set year
            for (size_t i = 4; i > 0; i--)
            {
                if (isNumber(entryDate[arrayIndex]))
                {
                    curretNumber += (int)pow(10, i - 1) * charToInt(entryDate[arrayIndex]);
                    arrayIndex++;
                }
                else {
                    return false;
                }
            }
            date[index] = curretNumber;
            curretNumber = 0;
            index++;
        }
        else {

            for (size_t i = 2; i > 0; i--)
            {
                if (isNumber(entryDate[arrayIndex]))
                {
                    curretNumber += (int)pow(10, i - 1) * charToInt(entryDate[arrayIndex]);
                    arrayIndex++;
                }
                else {
                    return false;
                }
            }
            date[index] = curretNumber;
            curretNumber = 0;
            index++;
        }
    }
    this->entryDate = DateTime(date[0], date[1], date[2]);
    return true;
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

char* Product::getDescription() {
    return this->description;
}

char* Product::getManufacturer() {
    return this->manufacturer;
}

DateTime& Product::getExpiryDate() {
    return this->expiryDate;
}

DateTime& Product::getEntryDate() {
    return this->entryDate;
}

int Product::getQuantity() {
    return this->quantity;
}

int Product::getLocation() {
    return this->location;
}

char* Product::getComment() {
    return this->comment;
}

bool Product::isNumber(const char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

int Product::charToInt(const char symbol)
{
   return (int)symbol - 48;
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

Unit Product::getUnit() {
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