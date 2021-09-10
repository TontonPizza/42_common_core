#include "Contact.hpp"


Contact::Contact(){}

Contact::~Contact() {}

void Contact::editData(int field, std::string data)
{
	this->data[field] = data;
}

std::string Contact::getData(int field) const
{
	return data[field];
}

void Contact::displayFull()
{
	std::cout << "_ _ _ _ _ _ _ _ _ _" << std::endl;
	for (int i = 0; i < DATA_LEN; i++)
	{
		std::cout << this->data[i];
		if ((this->data[i]).size() > 0)
			std::cout << std::endl;
	}
	std::cout << "_ _ _ _ _ _ _ _ _ _" << std::endl;

}

void Contact::displaySample(int index)
{
	std::stringstream convert;
	std::string word;
	convert << index;
	convert >> word;
	std::cout << '|';
	this->displayField(word);
	this->displayField(this->data[firstName]);
	this->displayField(this->data[lastName]);
	this->displayField(this->data[nickname]);
}

void Contact::displayField(std::string word)
{
	if (word.length() <= 10)
	{
		std::cout << std::setw(10);
		std::cout << word;
	}
	else
	{
		std::cout << word.substr(0, 9)  << '.';
	}
	std::cout << '|';
}