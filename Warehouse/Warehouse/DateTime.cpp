#include "DateTime.h"
#include<iostream>

DateTime::DateTime()
{
    setDefaultValues();
}

DateTime::DateTime(const int year, const int month, const int day)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

DateTime::DateTime(const char* date)
{
    int newDay = 0;
    int newMonth = 0;
    int newYear = 0;

    int countSlashesh = 0;
    int step = 0;
    int index = strlen(date) - 1;

    while (index >= 0)
    {
        if (date[index] == '/')
        {
            countSlashesh++;
            step = 0;
            index--;
            continue;
        }

        if (countSlashesh == 2)
        {
            if (isNumber(date[index]))
            {
                newYear += charToInt(date[index]) * pow(10, step);
                step++;
            }
            else {
                std::cout << "Invalid Date format" << std::endl;
                newYear = 0;
                break;
            }
        }

        if (countSlashesh == 1)
        {
            if (isNumber(date[index]))
            {
                newMonth += charToInt(date[index]) * pow(10, step);
                step++;
            }
            else {
                std::cout << "Invalid Date format" << std::endl;
                newMonth = 0;
                break;
            }
        }

        if (countSlashesh == 0)
        {
            if (isNumber(date[index]))
            {
                newDay += charToInt(date[index]) * pow(10, step);
                step++;
            }
            else {
                std::cout << "Invalid Date format" << std::endl;
                newDay = 0;
                break;
            }
        }

        index--;
    }

    if (isValidDate(newYear, newMonth, newDay))
    {
        this->year = newYear;
        this->month = newMonth;
        this->day = newDay;
    }
    else {
        setDefaultValues();
    }
}

int DateTime::getDay() const
{
	return day;
}

int DateTime::getMonth() const
{
	return month;
}

int DateTime::getYear() const
{
	return year;
}

bool DateTime::isValidDate(const int year, const int month, const int day)
{
    return !(year < MIN_YEAR || month < MIN_MONTH || month > MAX_MONTH || day < MIN_DAY || day > MAX_DAY);
}

DateTime& DateTime::operator = (const DateTime& dateTime) {
    if (this != &dateTime)
    {
		this->year = dateTime.year;
		this->month = dateTime.month;
		this->day = dateTime.day;
    }
    return *this;
}

bool DateTime::operator < (const DateTime& dateTime) {
	return (this->getDay() < dateTime.day) 
		&& (this->getMonth() < dateTime.month)
		&& (this->getYear() < dateTime.year);
}

std::ostream& operator<<(std::ostream& os, DateTime& date)
{
	os << date.getYear() << '/' << date.getMonth() << '/' << date.getDay();
	return os;
}

bool DateTime::isNumber(const char symbol)
{
    return symbol >= '0' && symbol <= '9';
}

int DateTime::charToInt(const char symbol)
{
    return (int)symbol - 48;
}

void DateTime::setDefaultValues()
{
    this->day = 0;
    this->month = 0;
    this->year = 0;
}