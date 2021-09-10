#include "Victim.hpp"

Victim::Victim()
{

}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some Random victom called " << this->getName() << " just appeared!" << std::endl;
}

Victim::Victim(Victim & T)
{
	this->_name = T.getName();
}

Victim::~Victim()
{
	std::cout << "Victim " << this->getName() << " just died for no apparent reason!" << std::endl;
}

Victim & Victim::operator=(const Victim & T)
{
	this->_name = T.getName();
	return (*this);
}

std::string	Victim::getName() const
{
	return (this->_name);
}

void	Victim::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream & operator<<(std::ostream & os, const Victim & T)
{
	os << "I'm " << T.getName() << " and I like otters!" << std::endl;
	return os;
}