#pragma once
#include "FileService.h"

class FileView
{
private:
	FileService service;

	char* enterString(const size_t length);
public:
	FileView();

	bool openView();
	bool closeView();
	bool saveView();
	bool saveAsView();
	bool helpView();
	bool addView();
};