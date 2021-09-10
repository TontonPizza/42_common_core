#include "FragTrap.hpp"

FragTrap::FragTrap(std::string data): _HP(100), _energyPoints(100), _level(1)
{
	std::cout << "FR4G-TP <"<< data <<"> start bootup sequence" << std::endl;
	this->_name = data;
	srand(time(0));
	this->initAttackPool();
}

FragTrap::FragTrap(): _HP(100), _energyPoints(100), _level(1)
{
	std::cout << "FR4G-TP <...> start bootup sequence" << std::endl;
	this->_name = "N.N.";
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
	std::cout << "I'm too pretty to die at level <"<< this->_level << ">" << std::endl;
}

FragTrap & FragTrap::operator=(const FragTrap & T)
{
	std::cout << "Assignation operator" << std::endl;
	this->_name = T._name;
	return (*this);
}

void 	FragTrap::initAttackPool()
{
	this->attackPointers[0] = &FragTrap::rangedAttack;
	this->attackPointers[1] = &FragTrap::explosiveAttack;
	this->attackPointers[2] = &FragTrap::thrustAttack;
	this->attackPointers[3] = &FragTrap::poisonAttack;
	this->attackPointers[4] = &FragTrap::meleeAttack;
}

void 	FragTrap::rangedAttack(const std::string &target)
{
	std::cout << "FR4G-TP <"<< this->_name<< "> attacks at range <"<< target <<">, causing <"<< this->_rangedAD << "> points of damage!" << std::endl;
}

void 	FragTrap::meleeAttack(const std::string &target)
{
	std::cout << "FR4G-TP <"<< this->_name<< "> attacks at melee <"<< target <<">, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
}

void 	FragTrap::poisonAttack(const std::string &target)
{
	std::cout << "FR4G-TP <"<< this->_name<< "> gives a rotten banana to <"<< target <<">, causing <"<< this->_rangedAD << "> points of damage!" << std::endl;
}

void 	FragTrap::explosiveAttack(const std::string &target)
{
	std::cout << "FR4G-TP <"<< this->_name<< "> puts firecracker in <"<< target <<">'s pocket, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
}

void 	FragTrap::thrustAttack(const std::string &target)
{
	std::cout << "FR4G-TP <"<< this->_name<< "> attacks <"<< target <<"> with a pointy stick, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
}

void 	FragTrap::vaulthunter_dot_exe(const std::string &target)
{
	if (this->_energyPoints < 25)
	{
		std::cout << "not enought energy !" << std::endl;
		return ;
	}
	this->_energyPoints -= 25;

	(this->*attackPointers[rand() % 5])(target);
}



void 	FragTrap::takeDamage(unsigned int amount)
{
	int val = (int)amount;
	if (val <= 0)
		return ;
	val = val - this->_armor;
	if (val <= 0)
		val = 1;
	this->_HP = this->_HP - val;
	if (this->_HP < 0)
		this->_HP = 0;
	std::cout << "FR4G-TP <"<< this->_name<< "> ";
	std::cout << "lost <" << val << "> damage after reduction, it now has <" << this->_HP << "> HP" << std::endl;
}

void 	FragTrap::beRepaired(unsigned int amount)
{
	int val = int(amount);
	if (val <= 0)
		return ;
	this->_HP = this->_HP + val;
	if (this->_HP > this->_maxHP)
		this->_HP = this->_maxHP;
	std::cout << "FR4G-TP <"<< this->_name<< "> ";
	std::cout << "recovered <" << val << "> HP, it now has <" << this->_HP << "> HP" << std::endl;
}
