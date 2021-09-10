#include "Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_value = 0;
}

Fixed::Fixed(const int i_val)
{
	std::cout << "Int constructor called" << std::endl;

	this->_fixed_point_value = i_val * pow(2, this->_fractional_bits);
}

Fixed::Fixed(const float f_val)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(f_val * pow(2, this->_fractional_bits));
}

Fixed::Fixed(const Fixed & T)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point_value = T.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return (((float)this->_fixed_point_value) / (pow(2, this->_fractional_bits)));
}

int 	Fixed::toInt(void) const
{
	return (this->_fixed_point_value / pow(2, this->_fractional_bits));
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

std::ostream &operator<<(std::ostream & os, const Fixed & fixed)
{
	os << fixed.toFloat();
	return (os);
}