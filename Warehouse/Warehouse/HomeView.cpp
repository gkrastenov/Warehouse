#include "HomeView.h"
#include<iostream>

using namespace std;

void HomeView::menuView()
{
	cout << "-------- Menu --------" << endl;
	cout << "-------- File commands --------" << endl;
	cout << "Open (open)" << endl;
	cout << "Close (close)" << endl;
	cout << "Save (save)" << endl;
	cout << "Save As (save as)" << endl;
	cout << "Help (help)" << endl;
	cout << "-------- Warehouse commands --------" << endl;
	cout << "Add (add)" << endl;
	cout << "Print (print)" << endl;
	cout << "Exit (exit)" << endl;
	cout << "Enter next command: " << endl;

}

bool HomeView::menu()
{
	menuView();

	char consoleCommand[20];
	cin.getline(consoleCommand, 20);
	if (compareStrings(consoleCommand, "open", getSize(consoleCommand), 4))
	{
		return false;
	}
	if (compareStrings(consoleCommand, "close", getSize(consoleCommand), 5))
	{
		return false;
	}
	if (compareStrings(consoleCommand, "add", getSize(consoleCommand), 3))
	{
		/*
		if (Class.add())
		{
			cout << "has been added new product" << endl;;
			return true;
		}
		else {
			cout << "Has not been added new product" << endl;;
			return false;
		}
		*/
	}
	if (compareStrings(consoleCommand, "exit", getSize(consoleCommand), 4))
	{
		return false;
	}
	if (compareStrings(consoleCommand, "help", getSize(consoleCommand), 4))
	{
		return false;
	}
	if (compareStrings(consoleCommand, "save as", getSize(consoleCommand), 7))
	{
		return false;
	}
	if (compareStrings(consoleCommand, "print", getSize(consoleCommand), 5))
	{
		return false;

	}
	if (compareStrings(consoleCommand, "clean", getSize(consoleCommand), 5))
	{
		return false;
	}

	cout << "Invalid command" << endl;
	return true;
}

bool HomeView::compareStrings(const char* input, const char* source,
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

size_t HomeView::getSize(const char* source)
{
	int index = 0;
	while (source[index] != '\0')
	{
		index++;
	}

	return index;
}
