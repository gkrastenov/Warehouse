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
	cout << "Print (print)" << endl;
	cout << "Add (add)" << endl;
	cout << "Remove (remove)" << endl;
	cout << "Clean (clean)" << endl;
	cout << "Exit (exit)" << endl;
	cout << "Enter next command: " << endl;
}

bool HomeView::menu()
{
	menuView();

	char consoleCommand[50];
	cin >> consoleCommand;
	cin.ignore();

	// File commands
	if (strcmp(consoleCommand, "open") == 0)
	{
		return fileView.openView();
	}

	if (strcmp(consoleCommand, "close") == 0)
	{
		return fileView.closeView();
	}

	if (strcmp(consoleCommand, "help") == 0)
	{
		return fileView.helpView();
	}

	if (strcmp(consoleCommand, "saveAs") == 0)
	{
		return fileView.saveAsView();;
	}

	if (strcmp(consoleCommand, "save") == 0)
	{
		return fileView.saveView();
	}

	// Product Commands
	if (strcmp(consoleCommand, "add") == 0)
	{
		if (fileView.addView())
		{
			cout << "Has been added new product" << endl;;
			return true;
		}

		cout << "Has not been added new product" << endl;;
		return true;
	}

	if (strcmp(consoleCommand, "log") == 0)
	{
		return fileView.logView();
	}

	if (strcmp(consoleCommand, "remove") == 0)
	{
		if (fileView.removeView())
		{
			return true;
		}

		cout << "Has not been removed new product" << endl;;
		return true;
	}

	if (strcmp(consoleCommand, "print") == 0)
	{
		return fileView.printView();
	}

	if (strcmp(consoleCommand, "clean") == 0)
	{
		return fileView.cleanView();
	}

	// Changes Commands

	// Program Commands
	if (strcmp(consoleCommand, "exit") == 0)
	{
		return false;
	}

	cout << "Invalid command" << endl;
	return true;
}