#include "ContactManager.hpp"

ContactManager::ContactManager()
{
	index = 0;
	dataFields[firstName] =			"FIRST NAME";
	dataFields[lastName] = 			"LAST NAME";
	dataFields[nickname] = 			"NICKNAME";
	dataFields[login] = 			"LOGIN";
	dataFields[postalAddress] = 	"POSTAL ADDRESS";
	dataFields[emailAddress] = 		"EMAIL ADDRESS";
	dataFields[phoneNumber] = 		"PHONE NUMBER";
	dataFields[birthdayDate] = 		"BIRTHDAY DATE";
	dataFields[favoriteMeal] = 		"FAVORITE MEAL";
	dataFields[underwearColor] = 	"UNDERWEAR COLOR";
	dataFields[darkestSecret] = 	"DARKEST SECRET";
}

ContactManager::~ContactManager(){}

void 	ContactManager::addContact()
{
	std::string buffer;
	if (index >= MAX_CONTACTS)
	{
		std::cout << "WARNING : NO SPACE LEFT ON DEVICE" << std::endl;
		std::cout << "previous data will be erased" << std::endl;
		std::cout << "continue ? (y/n)" <<std::endl;
		std::getline (std::cin, buffer);
		if (buffer != "y")
			return ;
	}
	index = index % MAX_CONTACTS;
	std::cout << "* * * * * * * * * * * * * * * * * * * *" << std::endl;
	for(int i = 0; i < DATA_LEN; i++)
	{
		std::cout << ">>> Enter new contact " << this->dataFields[i] << std::endl;
		std::getline (std::cin, buffer);
		this->contacts[this->index].editData(i, buffer);
	}
	std::cout << "* * * * * * * * * * * * * * * * * * * *" << std::endl;
	index = (index + 1);
}

void 	ContactManager::searchContact()
{
	int 		id;
	std::string input;
	std::stringstream convert;

	for(int i = 0; i < this->index; i++)
	{
		this->contacts[i].displaySample(i + 1);
		std::cout << std::endl;
	}
	if (this->index == 0)
	{
		std::cout << "-- ";
		return ;
	}
	std::cout << "please select a contact index" << std::endl;
	std::cin >> input;
	convert << input;
	convert >> id;
	if (id > 0 && id <= this->index)
		this->contacts[id - 1].displayFull();
	else
		this->searchContact();
}

