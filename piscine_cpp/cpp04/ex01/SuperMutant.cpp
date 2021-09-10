#include "SuperMutant.hpp"


SuperMutant::SuperMutant(): Enemy(170, "SuperMutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant & T)
{
	this->_hP = T.getHP();
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant & SuperMutant::operator=(const SuperMutant & T)
{
		this->_hP = T.getHP();
		return (*this);
}

void		SuperMutant::takeDamage(int damage)
{
	this->Enemy::takeDamage(damage - 3);
}
