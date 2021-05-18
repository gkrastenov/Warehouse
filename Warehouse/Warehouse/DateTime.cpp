#include "DateTime.h"
#include<iostream>

using namespace std;

DateTime::DateTime()
{
    day = 0;
	month = 0;
	year = 0;
}

DateTime::DateTime(const int year, const int month, const int day)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int DateTime::getDay()
{
	return day;
}

int DateTime::getMonth()
{
	return month;
}

int DateTime::getYear()
{
	return year;
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

bool DateTime::operator <= (const DateTime& dateTime) {
	return (this->getDay() <= dateTime.day) 
		&& (this->getMonth() <= dateTime.month)
		&& (this->getYear() <= dateTime.year);
}