#include "Weapon.hpp"

Weapon::Weapon(std::string data) : _refType(this->_type), _type(data)
{
}

Weapon::~Weapon()
{
}

const std::string &		Weapon::getType () const
{
	return this->_refType;
}

void 		Weapon::setType(std::string type)
{
	this->_type = type;
}