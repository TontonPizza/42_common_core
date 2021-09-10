#include "Sorcerer.hpp"


Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << this->getName() << ", " << this->getTitle() << ", is born!" << std::endl;
}

Sorcerer::Sorcerer()
{
}

Sorcerer::Sorcerer(Sorcerer & T)
{
	this->_name = T.getName();
	this->_title = T.getTitle();
}

Sorcerer::~Sorcerer()
{
	std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer & Sorcerer::operator=(const Sorcerer & T)
{
	this->_name = T.getName();
	this->_title = T.getTitle();
	return (*this);
}

std::string  Sorcerer::getName() const
{
	return (this->_name);
}

std::string  Sorcerer::getTitle() const
{
	return (this->_title);
}

std::ostream & operator<<(std::ostream & os, const Sorcerer & T)
{
	os << "I am " << T.getName() << ", " << T.getTitle() << ", and I like ponies!" << std::endl;
	return (os);
}

void 	Sorcerer::polymorph(const Victim &T) const
{
	T.getPolymorphed();
}

