#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string data):ClapTrap(data), _HP(100), _energyPoints(50), _level(1)
{
	std::cout << "ScavTrap <"<< data <<"> is coming, hide your girlfriends" << std::endl;
	this->_name = data;
	this->ClapTrap::_type = "SC4V-TP";
	this->ClapTrap::_energyPoints = 50;
	this->ClapTrap::_armor = 3;
	this->ClapTrap::_rangedAD = 15;
	this->ClapTrap::_meleeAD = 20;
	srand(time(0));
	this->initAttackPool();
}

ScavTrap::ScavTrap(): _HP(100), _energyPoints(50), _level(1)
{
	std::cout << "SC4V-TP <...> is coming, hide your girlfriends" << std::endl;
	this->_name = "N.N.";
	this->ClapTrap::_type = "SC4V-TP";
	this->ClapTrap::_energyPoints = 50;
	this->ClapTrap::_armor = 3;
	this->ClapTrap::_rangedAD = 15;
	this->ClapTrap::_meleeAD = 20;
	srand(time(0));
	this->initAttackPool();
}

ScavTrap::ScavTrap(ScavTrap & T)
{
	std::cout << "SC4V-TP <-> is coming, hide your girlfriends" << std::endl;
	this->_name = T._name;
}

ScavTrap::~ScavTrap()
{
	std::cout << "SC4V-TP : I'll be back <"<< this->_level << ">" << " <" << this->_HP << "> "<< std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & T)
{
	std::cout << "Assignation operator" << std::endl;
	this->_name = T._name;
	return (*this);
}

void 	ScavTrap::initAttackPool()
{
	this->challengePool[0] = &ScavTrap::challengeDDR;
	this->challengePool[1] = &ScavTrap::challengeChineseFeast;
}
void	ScavTrap::challengeChineseFeast(const std::string & target)
{
	std::cout << "SC4V-TP <"<< this->_name<< "> bets <"<< target <<"> " << "can't cook the Chinese Feast" << std::endl;
}

void	ScavTrap::challengeDDR(const std::string & target)
{
	std::cout << "SC4V-TP <"<< this->_name<< "> invites <"<< target <<"> to a Dance Dance Revolution contest" << std::endl;
}

void 	ScavTrap::challengeNewcomer(const std::string &target)
{
	this->_energyPoints -= 25;
	this->_energyPoints = this->_energyPoints < 0 ? 0 : this->_energyPoints;
	(this->*challengePool[rand() % 2])(target);
}
