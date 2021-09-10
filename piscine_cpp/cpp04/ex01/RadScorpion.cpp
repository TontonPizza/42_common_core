#include "RadScorpion.hpp"


RadScorpion::RadScorpion(): Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion & T)
{
	this->_hP = T.getHP();
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(const RadScorpion & T)
{
		this->_hP = T.getHP();
		return (*this);
}

void		RadScorpion::takeDamage(int damage)
{
	this->Enemy::takeDamage(damage - 3);
}
