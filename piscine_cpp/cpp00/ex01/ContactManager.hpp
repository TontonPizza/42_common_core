#ifndef PISCINE_CPP_CONTACTMANAGER_HPP
#define PISCINE_CPP_CONTACTMANAGER_HPP

#include "phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class ContactManager {

public:
					ContactManager();
					~ContactManager();
	void 			addContact();
	void 			searchContact();

private:
	std::string		dataFields[DATA_LEN];
	Contact			contacts[DATA_LEN];
	int				index;
};

#endif
