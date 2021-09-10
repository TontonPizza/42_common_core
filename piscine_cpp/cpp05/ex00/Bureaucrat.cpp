#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string & name, int grade): name(name)
{
	this->checkValue(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat & T): name(T.getName()), grade(T.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & T)
{
	this->grade = T.getGrade();
	return (*this);
}

int 			Bureaucrat::getGrade() const
{
	return (this->grade);
}

const std::string & 	Bureaucrat::getName() const
{
	return (this->name);
}

void 			Bureaucrat::incrementGrade(int val)
{
	this->checkValue(this->grade - val);
	this->grade = this->grade - val;
}

void 			Bureaucrat::decrementGrade(int val)
{
	this->checkValue(this->grade + val);
	this->grade = this->grade + val;
}

void 			Bureaucrat::checkValue(int val)
{
	if (val < 1)
		throw Bureaucrat::GradeTooHighException();
	if (val > 150)
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & os, const Bureaucrat & T)
{
	os << "<" << T.getName() << ">, " << "bureaucrat grade <" << T.getGrade() << ">" << std::endl;
	return (os);
}