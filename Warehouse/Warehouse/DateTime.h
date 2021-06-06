#pragma once
#include <iostream>

class DateTime
{
private:
	// day of month from 1 to 31
	const unsigned int MAX_DAY = 31;
	const unsigned int MIN_DAY = 0;

	// month of year from 0 to 12
	const unsigned int MAX_MONTH = 12;
	const unsigned int MIN_MONTH = 0;

	// year since 1900
	const unsigned int MIN_YEAR = 1900;

	unsigned int day;
	unsigned int month;
	unsigned int year;

public:
	DateTime();
	DateTime(const int year, const int month, const int day);

	// TODO: add const
	int getDay();
	int getMonth();
	int getYear();

	DateTime& operator = (const DateTime& date);
	bool operator <= (const DateTime& date);

	friend std::ostream& operator<<(std::ostream& os, DateTime& date);

};