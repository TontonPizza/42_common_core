#include "Ice.hpp"


Ice::Ice()
{
	this->AMateria::xp = 0;
	this->AMateria::type = "ice";
}

Ice::Ice(unsigned int xp)
{
	this->AMateria::xp = xp;
	this->AMateria::type = "ice";
}

Ice::Ice(const Ice & T)
{
	copyXP(T);
}

Ice::~Ice()
{
}

Ice & Ice::operator=(const Ice & T)
{
	copyXP(T);
	return (*this);
}

AMateria *		Ice::clone() const
{
	AMateria *result = new Ice(this->getXP());
	return (result);
}

unsigned int 	Ice::getXP() const
{
	return (this->AMateria::xp);
}

void			Ice::increaseXP()
{
	this->AMateria::xp += XP_PER_USE;
}

void 			Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"<<std::endl;
	this->increaseXP();
}


void			Ice::copyXP(const Ice & T)
{
	this->AMateria::xp = T.getXP();
}

std::string const & 	Ice::getType() const
{
	return (this->AMateria::type);
}