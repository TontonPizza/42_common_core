#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "N.A";
	this->_type = "vanilla";
}

Zombie::Zombie(std::string type, std::string name) : _type(type), _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->_name << " died" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}

void Zombie::setType(std::string type)
{
	this->_type = type;
}

void Zombie::announce() const
{
	std::cout << "<" << this->_name << " (" << this->_type << ")>";
	std::cout << " " << ". . .[¬º-°]¬" << std::endl;
}