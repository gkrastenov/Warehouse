#pragma once
#include "FileView.h"

class HomeView
{
private:
	FileView fileView;

	void menuView();

public:
	HomeView();

	bool menu();
};