#pragma once
#include "File.h"
class View
{
private:
    size_t MAX_CONSOLE_COMMAND = 20;
	File file;

	void menuView();
	bool compareStrings(const char* input, const char* source,
		const size_t inputSize, const size_t commandSize);
	size_t getSize(const char* source);
public:
	View();
	bool menu();
};

