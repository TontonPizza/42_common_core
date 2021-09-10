#include "Peon.hpp"

Peon::Peon() : Victim()
{

}

Peon::Peon(std::string name) : Victim(name)
{
	this->_name = name;
	std::cout << "Zig Zog." << std::endl;
}


Peon::Peon(Peon & T)
{
	this->_name = T.getName();
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon & Peon::operator=(const Peon & T)
{
	this->_name = T.getName();
	return (*this);
}

void	Peon::getPolymorphed() const
{
	std::cout << this->getName() << " has been turned into a pink pony!" << std::endl;
}