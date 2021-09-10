#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string data): _HP(100), _energyPoints(50), _level(1)
{
	std::cout << "SC4V-TP <"<< data <<"> is coming, hide your girlfriends" << std::endl;
	this->_name = data;
	srand(time(0));
	this->initAttackPool();
}

ScavTrap::ScavTrap(): _HP(100), _energyPoints(50), _level(1)
{
	std::cout << "SC4V-TP <...> is coming, hide your girlfriends" << std::endl;
	this->_name = "N.N.";
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
	std::cout << "SC4V-TP : I'll be back <"<< this->_level << ">" << std::endl;
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

void 	ScavTrap::rangedAttack(const std::string &target)
{
	std::cout << "SC4V-TP <"<< this->_name<< "> throws random stick to <"<< target <<">, causing <"<< this->_rangedAD << "> points of damage!" << std::endl;
}

void 	ScavTrap::meleeAttack(const std::string &target)
{
	std::cout << "SC4V-TP <"<< this->_name<< "> punches <"<< target <<"> in the gear, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
}

void 	ScavTrap::poisonAttack(const std::string &target)
{
	std::cout << "SC4V-TP <"<< this->_name<< "> uses toxic gas against <"<< target <<">, causing <"<< this->_rangedAD << "> points of damage!" << std::endl;
}

void 	ScavTrap::explosiveAttack(const std::string &target)
{
	std::cout << "SC4V-TP <"<< this->_name<< "> uses gravity against <"<< target <<">, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
}

void 	ScavTrap::thrustAttack(const std::string &target)
{
	std::cout << "SC4V-TP <"<< this->_name<< "> shows <"<< target <<"> how to fence, causing <"<< this->_meleeAD << "> points of damage!" << std::endl;
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

void 	ScavTrap::takeDamage(unsigned int amount)
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
	std::cout << "SC4V-TP <"<< this->_name<< "> ";
	std::cout << "lost <" << val << "> damage after reduction, it now has <" << this->_HP << "> HP" << std::endl;
}

void 	ScavTrap::beRepaired(unsigned int amount)
{
	int val = int(amount);
	if (val <= 0)
		return ;
	this->_HP = this->_HP + val;
	if (this->_HP > this->_maxHP)
		this->_HP = this->_maxHP;
	std::cout << "SC4V-TP <"<< this->_name<< "> ";
	std::cout << "recovered <" << val << "> HP, it now has <" << this->_HP << "> HP" << std::endl;
}
