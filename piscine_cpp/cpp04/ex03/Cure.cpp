#include "Cure.hpp"


Cure::Cure()
{
	this->AMateria::xp = 0;
	this->AMateria::type = "cure";
}

Cure::Cure(unsigned int xp)
{
	this->AMateria::xp = xp;
	this->AMateria::type = "cure";
}

Cure::Cure(const Cure & T)
{
	copyXP(T);
}

Cure::~Cure()
{
}

Cure & Cure::operator=(const Cure & T)
{
	copyXP(T);
	return (*this);
}

AMateria *		Cure::clone() const
{
	AMateria *result = new Cure(this->getXP());
	return (result);
}

unsigned int 	Cure::getXP() const
{
	return (this->AMateria::xp);
}

void			Cure::increaseXP()
{
	this->AMateria::xp += XP_PER_USE;
}

void 			Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
	increaseXP();
}


void			Cure::copyXP(const Cure & T)
{
	this->AMateria::xp = T.getXP();
}

std::string const & 	Cure::getType() const
{
	return (this->AMateria::type);
}
