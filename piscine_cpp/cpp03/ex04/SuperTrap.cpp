#include "SuperTrap.hpp"


SuperTrap::SuperTrap():ClapTrap(), FragTrap(), NinjaTrap()
{

}

SuperTrap::SuperTrap(std::string name):ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	std::cout << "Supertrap constructed" << std::endl;
	this->ClapTrap::_type = "SUP3R-TP";
	this->ClapTrap::_armor = this->FragTrap::_armor;
	this->ClapTrap::_HP = this->FragTrap::_HP;
	this->ClapTrap::_maxHP = this->FragTrap::_maxHP;
	this->ClapTrap::_level = 1;
	this->ClapTrap::_energyPoints = this->NinjaTrap::_energyPoints;
	this->ClapTrap::_maxEnergyPoint = this->NinjaTrap::_energyPoints;
	this->ClapTrap::_meleeAD = this->NinjaTrap::_meleeAD;
	this->ClapTrap::_rangedAD = this->FragTrap::_rangedAD;

}

SuperTrap::SuperTrap(SuperTrap & T)
{
	this->_name = T._name;
}

SuperTrap::~SuperTrap()
{
	std::cout << "bye SUP3R-TP" << std::endl;
}

SuperTrap & SuperTrap::operator=(const SuperTrap & T)
{
	this->_name = T._name;
	return (*this);
}

void SuperTrap::meleeAttack(const std::string &target)
{
	std::cout << "SUP3R-TP use Ninja melee Attack : " << std::endl;
	this->NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(const std::string &target)
{
	std::cout << "SUP3R-TP use Frag ranged Attack :" << std::endl;
	this->FragTrap::rangedAttack(target);
}