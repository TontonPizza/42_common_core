#include "JunkJet.hpp"

JunkJet::JunkJet(): AWeapon("Junk-Jet", 5, 21)
{

}

JunkJet::JunkJet(JunkJet & T)
{
	this->AWeapon::_name = T.getName();
}

JunkJet::~JunkJet()
{
}

JunkJet & JunkJet::operator=(const JunkJet & T)
{
	this->AWeapon::_name = T.getName();
	this->AWeapon::_aPCost = T.getAPCost();
	this->AWeapon::_damagePoint = T.getDamage();
	return (*this);
}

void 	JunkJet::attack() const
{
	std::cout << "* throws random stuff *" << std::endl;
}