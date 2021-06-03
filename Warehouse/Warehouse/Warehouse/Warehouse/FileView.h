#pragma once
class FileView
{
private:

public:
	FileView();

	bool openView();
	bool closeView();
	bool saveView();
	bool saveAsView();
	bool helpView();
};