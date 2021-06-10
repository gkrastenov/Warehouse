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

	bool isNumber(const char symbol);
	int charToInt(const char symbol);
	void setDefaultValues();

public:
	DateTime();
	DateTime(const int year, const int month, const int day);
	DateTime(const char* date);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	bool isValidDate(const int year, const int month, const int day);

	DateTime& operator = (const DateTime& dateTime);
	bool operator < (const DateTime& dateTime);
	bool operator != (const DateTime& dateTime);
	bool operator == (const DateTime& dateTime);
	bool operator <= (const DateTime& dateTime);
	bool operator >= (const DateTime& dateTime);

	friend std::ostream& operator<<(std::ostream& os, const DateTime& date);
};