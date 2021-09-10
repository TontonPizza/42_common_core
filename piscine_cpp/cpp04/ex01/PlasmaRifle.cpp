#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21)
{

}

PlasmaRifle::PlasmaRifle(PlasmaRifle & T)
{
	this->AWeapon::_name = T.getName();
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle & PlasmaRifle::operator=(const PlasmaRifle & T)
{
	this->AWeapon::_name = T.getName();
	this->AWeapon::_aPCost = T.getAPCost();
	this->AWeapon::_damagePoint = T.getDamage();
	return (*this);
}

void 	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}