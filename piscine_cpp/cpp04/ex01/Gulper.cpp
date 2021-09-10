#include "Gulper.hpp"


Gulper::Gulper(): Enemy(80, "Gulper")
{
	std::cout << "* Beuhh *" << std::endl;
}

Gulper::Gulper(Gulper & T)
{
	this->_hP = T.getHP();
}

Gulper::~Gulper()
{
	std::cout << "* Rrrr *" << std::endl;
}

Gulper & Gulper::operator=(const Gulper & T)
{
	this->_hP = T.getHP();
	return (*this);
}

void		Gulper::takeDamage(int damage)
{
	this->Enemy::takeDamage(damage - 3);
}
