#include "HomeView.h"
#include<iostream>

using namespace std;

HomeView::HomeView()
{
	this->fileView = FileView();
}

void HomeView::menuView()
{
	cout << "-------- Menu --------" << endl;
	cout << "-------- File commands --------" << endl;
	cout << "Open (open)" << endl;
	cout << "Close (close)" << endl;
	cout << "Save (save)" << endl;
	cout << "Save As (saveAs)" << endl;
	cout << "Help (help)" << endl;
	cout << "-------- Warehouse commands --------" << endl;
	cout << "Add (add)" << endl;
	cout << "Print (print)" << endl;
	cout << "Clean (clean)" << endl;
	cout << "Exit (exit)" << endl;
	cout << "Enter next command: " << endl;
}

bool HomeView::menu()
{
	menuView();


	char consoleCommand[20];
	cin.getline(consoleCommand, 20);

	// File commands
	if (compareStrings(consoleCommand, "open", getSize(consoleCommand), 4))
	{
		return fileView.openView();
	}

	if (compareStrings(consoleCommand, "close", getSize(consoleCommand), 5))
	{
		return fileView.closeView();
	}

	if (compareStrings(consoleCommand, "help", getSize(consoleCommand), 4))
	{
		return fileView.helpView();
	}

	if (compareStrings(consoleCommand, "saveAs", getSize(consoleCommand), 6))
	{
		return fileView.saveAsView();;
	}

	if (compareStrings(consoleCommand, "save", getSize(consoleCommand), 4))
	{
		return fileView.saveView();
	}

	// Product Commands
	if (compareStrings(consoleCommand, "add", getSize(consoleCommand), 3))
	{
		if (fileView.addView())
		{
			cout << "has been added new product" << endl;;
			return true;
		}

		cout << "Has not been added new product" << endl;;
		return true;
	}

	if (compareStrings(consoleCommand, "exit", getSize(consoleCommand), 4))
	{
		return false;
	}

	if (compareStrings(consoleCommand, "print", getSize(consoleCommand), 5))
	{
		return fileView.printView();
	}

	if (compareStrings(consoleCommand, "clean", getSize(consoleCommand), 5))
	{
		return fileView.cleanView();
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
