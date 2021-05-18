#include "View.h"
#include <iostream>
using namespace std;

View::View()
{
	file = File();
}
bool View::menu()
{
	menuView();

	char consoleCommand[20];
	cin.getline(consoleCommand, 20);

	if (compareStrings(consoleCommand, "add", getSize(consoleCommand), 3))
	{
		return file.add();
	}

	return false;
}

void View::menuView()
{
	cout << "-------- Menu --------" << endl;
	cout << "Add (add)" << endl;
	cout << "Print (print)" << endl;
	cout << "Help (help)" << endl;
	cout << "Exit (exit)" << endl;
}

bool View::compareStrings(const char* input, const char* source, 
	const size_t inputSize, const size_t commandSize)
{
	if (inputSize != commandSize)
	{
		return false;
	}

	for (size_t i = 0; i < commandSize; i++)
	{
		if (input[i] != source[i])
		{
			return false;
		}
	}

	return true;
}

size_t View::getSize(const char* source)
{
	int index = 0;
	while (source[index] != '\0')
	{
		index++;
	}

	return index;
}