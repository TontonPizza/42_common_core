#include "Enemy.hpp"

Enemy::Enemy()
{

}

Enemy::Enemy(int hp, std::string const & type): _hP(hp), _type(type)
{

}

Enemy::Enemy(Enemy & T)
{
	this->_hP = T.getHP();
}

Enemy::~Enemy()
{
}

Enemy & Enemy::operator=(const Enemy & T)
{
	this->_hP = T.getHP();
	return (*this);
}

void 	Enemy::takeDamage(int damage)
{
	if (damage < 0)
		return ;
	this->_hP = std::max(0, this->_hP - damage);
}

int 	Enemy::getHP() const
{
	return (this->_hP);
}

std::string Enemy::getType() const
{
	return (this->_type);
}