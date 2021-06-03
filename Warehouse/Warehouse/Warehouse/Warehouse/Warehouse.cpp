#include <iostream>
#include "HomeView.h"

int main()
{
	HomeView view = HomeView();

	while (true)
	{
		if (view.menu() == false)
		{
			break;
		}
	}
}