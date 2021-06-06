#pragma once
#include "FileService.h"
#include "DateTime.h"


class FileView
{
private:
	FileService service;

	char* enterString(const size_t length);
	bool isValidEnterDate(const DateTime& dateTime);

public:
	FileView();

	bool openView();
	bool closeView();
	bool saveView();
	bool saveAsView();
	bool helpView();
	bool exitView();
	bool addView();
	bool printView();
};