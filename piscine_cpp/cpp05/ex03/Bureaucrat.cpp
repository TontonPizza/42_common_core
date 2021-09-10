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

void 			Bureaucrat::signForm(Form * F)
{
	if (this->getGrade() < F->getSignGrade())
		std::cout << "<" <<this->name << " " << this->getGrade() << " > signs <" << F->getName() <<" "<< F->getSignGrade() << ">" << std::endl;
	else
		std::cout << "<" <<this->name << " " << this->getGrade() << " > cannot sign <" << F->getName() <<" "<< F->getSignGrade() << ">" << std::endl;
}

void 			Bureaucrat::executeForm(const Form &form)
{
	if (this->getGrade() > form.getExecGrade())
	{
		std::cout << "<" << this->getName() << "> can't execute <" << form.getName() << ">" << std::endl;
		throw Bureaucrat::GradeTooLowException();
	}
	else if(!form.getStatus())
	{
		std::cout << "<" << this->getName() << "> can't execute <" << form.getName() << ">" << std::endl;
		throw Bureaucrat::NotSignedException();
	}
	else
	{
		std::cout << "<" << this->getName() << "> execute <" << form.getName() << ">" << std::endl;
		form.execute(*this);
	}
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