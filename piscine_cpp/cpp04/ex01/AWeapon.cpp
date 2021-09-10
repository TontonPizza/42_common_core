#include "AWeapon.hpp"


AWeapon::AWeapon()
{

}

AWeapon::AWeapon(std::string const & name, int apcost, int damage):_name(name), _aPCost(apcost), _damagePoint(damage)
{

}

AWeapon::AWeapon(AWeapon & T)
{
	this->_name = T.getName();
}

AWeapon::~AWeapon()
{
}

AWeapon & AWeapon::operator=(const AWeapon & T)
{
	this->_name = T.getName();
	return (*this);
}

std::string AWeapon::getName() const
{
	return (this->_name);
}

int 	AWeapon::getAPCost() const
{
	return this->_aPCost;
}

int 	AWeapon::getDamage() const
{
	return this->_damagePoint;
}