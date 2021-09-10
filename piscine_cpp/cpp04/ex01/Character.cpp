#include "Character.hpp"

Character::Character()
{

}

Character::Character(std::string const & name):  _name(name), _aP(40)
{

}

Character::Character(Character & T)
{
	this->_aP = T.getAP();
}

Character::~Character()
{
}

Character & Character::operator=(const Character & T)
{
	this->_aP = T._aP;
	return (*this);
}

void 	Character::attack(Enemy *enemy)
{
	if (!this->_weapon)
		return ;
	if (_aP < this->_weapon->getAPCost())
	{
		std::cout << "Not enought AP" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks " << enemy->getType() << " with " << this->_weapon->getName() << std::endl;
	this->_aP = this->_aP - this->_weapon->getAPCost();
	this->_weapon->attack();
	enemy->takeDamage(this->_weapon->getDamage());
	if (enemy->getHP() <= 0)
	{
		delete enemy;
		enemy = NULL;
	}
}

void 	Character::recoverAP()
{
	this->_aP = std::min(40, this->_aP + 10);
}

void 	Character::equip(AWeapon *wp)
{
	this->_weapon = wp;
}

std::string 		Character::getName() const
{
	return (this->_name);
}

int 		Character::getAP() const
{
	return this->_aP;
}

std::string			Character::getWeapon() const
{
	if (!this->_weapon)
		return ("is unarmed");
	return ("wields a " + this->_weapon->getName());
}

std::ostream  & operator<<(std::ostream & os, const Character & T)
{
	os << T.getName() << " has " << T.getAP() << " AP and " << T.getWeapon() << std::endl;
	return (os);
}