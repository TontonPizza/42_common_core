#include "FragTrap.hpp"

FragTrap::FragTrap(std::string data):ClapTrap(data), _HP(100), _energyPoints(100), _level(1)
{
	std::cout << "FR4G-TP <"<< data <<"> start bootup sequence" << std::endl;
	this->_name = data;
	this->ClapTrap::_type = "FR4G-TP";
	this->ClapTrap::_armor = 5;
	this->ClapTrap::_rangedAD = 20;
	this->ClapTrap::_meleeAD = 30;
	srand(time(0));
	this->initAttackPool();
}

FragTrap::FragTrap(): _HP(100), _energyPoints(100), _level(1)
{
	std::cout << "FR4G-TP <...> start bootup sequence" << std::endl;
	this->_name = "N.N.";
	this->ClapTrap::_type = "FR4G-TP";
	this->ClapTrap::_armor = 5;
	this->ClapTrap::_rangedAD = 20;
	this->ClapTrap::_meleeAD = 30;
	srand(time(0));
	this->initAttackPool();
}

FragTrap::FragTrap(FragTrap & T)
{
	std::cout << "FR4G-TP <-> start bootup sequence" << std::endl;
	this->_name = T._name;
}

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TP I'm too pretty to die at level <"<< this->_level << ">" << " <" << this->_HP << ">" << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap & T)
{
	std::cout << "Assignation operator" << std::endl;
	this->_name = T._name;
	return (*this);
}

void 	FragTrap::initAttackPool()
{
	this->attackPointers[0] = &ClapTrap::rangedAttack;
	this->attackPointers[1] = &ClapTrap::explosiveAttack;
	this->attackPointers[2] = &ClapTrap::thrustAttack;
	this->attackPointers[3] = &ClapTrap::poisonAttack;
	this->attackPointers[4] = &ClapTrap::meleeAttack;
}


void 	FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	if (this->_energyPoints < 25)
	{
		std::cout << "FR4G-TP :not enought energy !" << std::endl;
		return ;
	}
	this->_energyPoints -= 25;

	(this->*attackPointers[rand() % 5])(target);
}

