#include <iostream>
#include <string>
#include "myheader.h"



int main() {
	addressBook book1;
	book1.bookSize = 0;
	int select = 0;
	while (true)
	{
		menuDisplay();
		std::cin >> select;
		switch (select)
		{
		case 1:
			addContact(&book1);
			break;
		case 2:
			disContact(&book1);
			break;
		case 3:
			delContact(&book1);
			break;
		case 4:
			searchContact(&book1);
			break;
		case 5:
			modifyContact(&book1);
			break;
		case 6:
			clearContact(&book1);
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
	}
}