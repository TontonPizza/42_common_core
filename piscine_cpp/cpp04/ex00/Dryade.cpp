#include "Dryade.hpp"

Dryade::Dryade() : Victim()
{

}

Dryade::Dryade(std::string name) : Victim(name)
{
	this->_name = name;
	std::cout << "Ah, the great outdoors!" << std::endl;
}


Dryade::Dryade(Dryade & T)
{
	this->_name = T.getName();
}

Dryade::~Dryade()
{
	std::cout << "For the trees." << std::endl;
}

Dryade & Dryade::operator=(const Dryade & T)
{
	this->_name = T.getName();
	return (*this);
}

void	Dryade::getPolymorphed() const
{
	std::cout << this->getName() << " is immune to magic" << std::endl;
}