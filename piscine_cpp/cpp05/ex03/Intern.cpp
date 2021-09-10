#include "Intern.hpp"

Intern::Intern()
{
	initFormWriter();
}

Intern::Intern(Intern & T)
{
	(void)T;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(const Intern & T)
{
	(void)T;
	return (*this);
}

void 	Intern::initFormWriter()
{
	this->formWriters[0] = &Intern::makeCreationForm;
	this->formWriters[1] = &Intern::makeRequestForm;
	this->formWriters[2] = &Intern::makePardonForm;
}

Form * Intern::makeCreationForm(std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

Form * Intern::makePardonForm(std::string &target)
{
	return (new PresidentialPardonForm(target));
}

Form * Intern::makeRequestForm(std::string &target)
{
	return (new RobotomyRequestForm(target));
}

Form *	Intern::makeForm(std::string identifier, std::string target)
{
	Form *ptr;
	int k = scoreInput(identifier);
	if (k < 0 || k > 2)
		throw Intern::IdentifierException();
	else
	{
		ptr = (this->*formWriters[k])(target);
		std::cout << "Intern created form <" << ptr->getName() << ">" << std::endl;
		return ptr;
	}
}


int 	Intern::scoreInput(std::string input)
{
	if (input == "shrubbery creation")
		return (0);
	if (input == "robotomy request")
		return (1);
	if (input == "presidential pardon")
		return (2);
	return (-1);
}