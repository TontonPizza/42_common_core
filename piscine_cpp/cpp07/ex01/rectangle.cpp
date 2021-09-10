#include "rectangle.hpp"


rectangle::rectangle()
{
}

rectangle::rectangle(int x, int y): x(x), y(y)
{}

rectangle::rectangle(const rectangle & T): x(T.getX()), y(T.getY())
{
}

rectangle::~rectangle()
{
}

rectangle & rectangle::operator=(const rectangle & T)
{
	this->x = T.getX();
	this->y = T.getY();
	return (*this);
}

int 		rectangle::getX() const

{
	return this->x;
}

int 		rectangle::getY() const
{
	return this->y;
}

int 		rectangle::area() const
{
	return (this->getX() * this->getY());
}

bool 		rectangle::operator<(const rectangle & T)
{
	return (this->area() < T.area());
}

bool 		rectangle::operator>(const rectangle & T)
{
	return (this->area() > T.area());
}

std::ostream  & operator<<(std::ostream & os, const rectangle & T)
{
	os << "(" <<T.getX() <<", ";
	os << T.getY() << ")";
	os << " area = " << T.area();
	return os;
}
