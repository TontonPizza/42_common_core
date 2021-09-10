#include "AMateria.hpp"


AMateria::AMateria(): xp(0), type("empty")
{

}

AMateria::AMateria(const AMateria & T)
{
	this->xp = T.getXP();
}

AMateria::~AMateria()
{
}

AMateria & AMateria::operator=(const AMateria & T)
{
	this->xp = T.getXP();
	this->type = T.getType();
	return (*this);
}

AMateria::AMateria(std::string const & type): xp(0), type(type)
{
}

std::string const	&		AMateria::getType() const
{
	return (this->type);
}

unsigned int				AMateria::getXP() const
{
	return (this->xp);
}