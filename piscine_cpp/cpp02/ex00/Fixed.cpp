#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_value = 0;
}

Fixed::Fixed(int val): _fixed_point_value(val)
{

}

Fixed::Fixed(Fixed & T)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point_value = T.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=(const Fixed & T)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed_point_value = T.getRawBits();
	return (*this);
};

int 	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

void 	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBit member function called" << std::endl;
	this->_fixed_point_value = raw;
}