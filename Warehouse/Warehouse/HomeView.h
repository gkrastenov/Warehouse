#pragma once
class HomeView
{
private:
	void menuView();
	bool compareStrings(const char* input, const char* source,
		const size_t inputSize, const size_t commandSize);
	size_t getSize(const char* source);
public:
	bool menu();
};

