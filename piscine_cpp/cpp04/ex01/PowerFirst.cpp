#include "PowerFist.hpp"

PowerFist::PowerFist(): AWeapon("Power First", 8, 50)
{

}

PowerFist::PowerFist(PowerFist & T)
{
	this->AWeapon::_name = T.getName();
}

PowerFist::~PowerFist()
{
}

PowerFist & PowerFist::operator=(const PowerFist & T)
{
	this->AWeapon::_name = T.getName();
	this->AWeapon::_aPCost = T.getAPCost();
	this->AWeapon::_damagePoint = T.getDamage();
	return (*this);
}

void 	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}
