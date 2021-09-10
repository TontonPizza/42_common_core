#include "Bahamut.hpp"


Bahamut::Bahamut()
{
	this->AMateria::xp = 0;
	this->AMateria::type = "Bahamut";
}

Bahamut::Bahamut(unsigned int xp)
{
	this->AMateria::xp = xp;
	this->AMateria::type = "Bahamut";
}

Bahamut::Bahamut(const Bahamut & T)
{
	copyXP(T);
}

Bahamut::~Bahamut()
{
}

Bahamut & Bahamut::operator=(const Bahamut & T)
{
	copyXP(T);
	return (*this);
}

AMateria *		Bahamut::clone() const
{
	AMateria *result = new Bahamut(this->getXP());
	return (result);
}

unsigned int 	Bahamut::getXP() const
{
	return (this->AMateria::xp);
}

void			Bahamut::increaseXP()
{
	this->AMateria::xp += XP_PER_USE;
}

void 			Bahamut::use(ICharacter &target)
{
	std::cout << "* Obliterates " << target.getName() << " *" <<std::endl;
	increaseXP();
}


void			Bahamut::copyXP(const Bahamut & T)
{
	this->AMateria::xp = T.getXP();
}

std::string const & 	Bahamut::getType() const
{
	return (this->AMateria::type);
}
