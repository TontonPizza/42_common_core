#include "Human.hpp"

std::string Human::identify()
{
	return (this->_brain.identify());
}

const Brain & Human::getBrain() const
{
	return (this->_brain);
}