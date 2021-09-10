#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void test_intern(std::string formName)
{
	std::cout << "test : intern creates form " << formName << std::endl;
	Intern intern;
	Form * genericForm = NULL;

	try
	{
		genericForm = intern.makeForm(formName, "here");
		std::cout << "Succes making form" << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	if (genericForm)
		std::cout << *genericForm << std::endl;
}

int main()
{
	test_intern("presidential pardon");
	std::cin.get();
	test_intern("robotomy request");
	std::cin.get();
	test_intern("shrubbery creation");
	std::cin.get();
	test_intern("contact form");

}
