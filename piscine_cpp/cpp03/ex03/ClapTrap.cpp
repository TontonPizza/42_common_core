#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_type = "CL4P-TP";
	std::cout << "CL4P-TP constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string data): _HP(100), _energyPoints(100), _level(1)
{
	this->_type = "CL4P-TP";
	std::cout << "CL4P-TP <"<< data <<"> constructor" << std::endl;
	this->_name = data;
	this->_meleeAD = 0;
	this->_rangedAD = 0;
	srand(time(0));
}

ClapTrap::~ClapTrap()
{
	std::cout << "CL4P-TP destructor" << std::endl;
}

void 	ClapTrap::rangedAttack(const std::string &target)
{
	std::cout << this->_type <<" <"<< this->_name<< "> attacks at range <"<< target <<">, causing <"<< this->_rangedAD << "> points of damage!" << std::endl;
}

void 	ClapTrap::meleeAttack(const std::string &target)
{
	std::cout << this->_type <<" <"<< this->_name<< "> attacks at melee <"<< target <<">, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
}

void 	ClapTrap::poisonAttack(const std::string &target)
{
	std::cout << this->_type <<" <"<< this->_name<< "> gives a rotten banana to <"<< target <<">, causing <"<< this->_rangedAD << "> points of damage!" << std::endl;
}

void 	ClapTrap::explosiveAttack(const std::string &target)
{
	std::cout << this->_type <<" <"<< this->_name<< "> puts firecracker in <"<< target <<">'s pocket, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
}

void 	ClapTrap::thrustAttack(const std::string &target)
{
	std::cout << this->_type <<" <"<< this->_name<< "> attacks <"<< target <<"> with a pointy stick, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
}

void 	ClapTrap::takeDamage(unsigned int amount)
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
	std::cout << this->_type <<" <"<< this->_name<< "> ";
	std::cout << "lost <" << val << "> damage after reduction, it now has <" << this->_HP << "> HP" << std::endl;
}

void 	ClapTrap::beRepaired(unsigned int amount)
{
	int val = int(amount);
	if (val <= 0)
		return ;
	this->_HP = this->_HP + val;
	if (this->_HP > this->_maxHP)
		this->_HP = this->_maxHP;
	std::cout << this->_type << " <"<< this->_name<< "> ";
	std::cout << "recovered <" << val << "> HP, it now has <" << this->_HP << "> HP" << std::endl;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &T)
{
	std::cout << "Assignation operator" << std::endl;
	this->_name = T._name;
	return (*this);
}