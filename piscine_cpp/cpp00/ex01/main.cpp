#include "phonebook.hpp"
#include "Contact.hpp"
#include "ContactManager.hpp"
#include <iostream>
#include <string>


int main()
{
	ContactManager contactManager;
	std::string command = "";
	int	last_is_search = 0;


	while (command != "EXIT")
	{
		if (last_is_search == 0)
			std::cout << "-- ";
		std::getline (std::cin, command);
		if (command == "ADD")
			contactManager.addContact();
		else if (command == "SEARCH")
		{
			contactManager.searchContact();
			last_is_search = 1;
			continue;
		}
		last_is_search = 0;
	}
	std::cout << "bye" << std::endl;
}