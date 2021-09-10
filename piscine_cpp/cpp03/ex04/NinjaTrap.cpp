#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap(): ClapTrap(), _HP(60), _energyPoints(120), _level(1)
{
	std::cout << "N1NJ4-TP <.> is here" << std::endl;
	this->ClapTrap::_type = "N1NJ4-TP";
	this->ClapTrap::_armor = 0;
	this->ClapTrap::_rangedAD = 5;
	this->ClapTrap::_meleeAD = 60;
}

NinjaTrap::NinjaTrap(std::string name): ClapTrap(name), _HP(60), _energyPoints(120), _level(1)
{
	std::cout << "N1NJ4-TP <" << name << ">" << " is here" << std::endl;
	this->ClapTrap::_type = "N1NJ4-TP";
	this->ClapTrap::_armor = 0;
	this->ClapTrap::_rangedAD = 5;
	this->ClapTrap::_meleeAD = 60;
}

NinjaTrap::NinjaTrap(NinjaTrap & T)
{
	std::cout << "N1NJ4-TP <" << this->_name << ">" << " is here" << std::endl;
	this->_name = T._name;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "N1NJ4-TP <" << this->_name << "> is dead " << this->_HP << " " << this->_energyPoints << " " << this->_level <<  std::endl;

}

NinjaTrap & NinjaTrap::operator=(const NinjaTrap & T)
{
		this->_name = T._name;
		return (*this);
}


void NinjaTrap::ninjaShoebox(ClapTrap &T)
{
	std::cout << "N1NJ4-TP <" << this->_name << ">" << " use ClapAttack" << std::endl;
	T.meleeAttack("plop");
}

void NinjaTrap::ninjaShoebox(FragTrap &T)
{
	std::cout << "N1NJ4-TP <" << this->_name << ">" << " use FragAttack" << std::endl;
	T.meleeAttack("pouet");
}

void NinjaTrap::ninjaShoebox(NinjaTrap &T)
{
	std::cout << "N1NJ4-TP <" << this->_name << ">" << " use NinjaAttack" << std::endl;
	T.meleeAttack("plip");
}

void NinjaTrap::ninjaShoebox(ScavTrap &T)
{
	std::cout << "N1NJ4-TP <" << this->_name << ">" << " use ScavAttack" << std::endl;
	T.meleeAttack("plouic");
}
