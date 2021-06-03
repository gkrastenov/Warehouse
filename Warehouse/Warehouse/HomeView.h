#pragma once
#include "FileView.h"
class HomeView
{
private:
	FileView fileView;

	void menuView();
	bool compareStrings(const char* input, const char* source,
		const size_t inputSize, const size_t commandSize);
	size_t getSize(const char* source);
public:
	HomeView();

	bool menu();
};

