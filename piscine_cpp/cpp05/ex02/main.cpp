#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test_too_low_to_sign()
{
	std::cout << "test : too low to sign" << std::endl;
	Bureaucrat low("Low Bureaucrat", 150);
	ShrubberyCreationForm srb("home");

	try
	{
		srb.beSigned(low);
	}
	catch (std::exception & e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}

void test_too_low_to_execute()
{
	std::cout << "test : too low to execute" << std::endl;

	Bureaucrat high("High Bureaucrat", 1);
	Bureaucrat low("Low Bureaucrat", 150);
	ShrubberyCreationForm srb("home");

	srb.beSigned(high);

	try
	{
		std::cout << "trying to execute , form lvl 137 with Bureaucrat lvl 150" << std::endl;
		srb.execute(low);
		std::cout << "Success" << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << "Exception : ";
		std::cout << e.what() << std::endl;
	}

}

void test_wrong_file_access()
{
	std::cout << "test : wrong file access" << std::endl;

	Bureaucrat high("High Bureaucrat", 1);
	ShrubberyCreationForm srb("LOCKED");

	srb.beSigned(high);

	try
	{
		std::cout << "trying to execute , form lvl 137 with Bureaucrat lvl 1" << std::endl;
		srb.execute(high);
		std::cout << "Success" << std::endl;

	}
	catch(std::exception & e)
	{
		std::cout << "Exception : ";
		std::cout << e.what() << std::endl;
	}
}

void test_execute()
{
	std::cout << "test : normal execution" << std::endl;

	Bureaucrat high("High Bureaucrat", 1);
	ShrubberyCreationForm srb("home");

	srb.beSigned(high);

	try
	{
		std::cout << "trying to execute , form lvl 137 with Bureaucrat lvl 1" << std::endl;
		srb.execute(high);
		std::cout << "Success" << std::endl;

	}
	catch(std::exception & e)
	{
		std::cout << "Exception : ";
		std::cout << e.what() << std::endl;
	}
}

void 	test_robotomy()
{
	std::cout << "test : robotomy randomness" << std::endl;

	Bureaucrat high("High Bureaucrat", 1);
	RobotomyRequestForm rbf("home");

	rbf.beSigned(high);

	try
	{
		std::cout << "trying to execute , form lvl 45 with Bureaucrat lvl 1" << std::endl;
		rbf.execute(high);
		std::cout << "Success" << std::endl;

	}
	catch(std::exception & e)
	{
		std::cout << "Exception : ";
		std::cout << e.what() << std::endl;
	}
}

void	test_pardon_form()
{
	std::cout << "test : pardon" << std::endl;

	Bureaucrat high("High Bureaucrat", 1);
	PresidentialPardonForm rbf("home");

	rbf.beSigned(high);

	try
	{
		std::cout << "trying to execute , form lvl 5 with Bureaucrat lvl 1" << std::endl;
		rbf.execute(high);
		std::cout << "Success" << std::endl;

	}
	catch(std::exception & e)
	{
		std::cout << "Exception : ";
		std::cout << e.what() << std::endl;
	}
}

void 	test_bureaucrat_execute()
{
	std::cout << "test : bureaucrat execute" << std::endl;

	Bureaucrat high("High Bureaucrat", 1);
	ShrubberyCreationForm rbf("test_bureaucrat_exec");

	try
	{
		high.executeForm(rbf);
	}
	catch(std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{

	test_too_low_to_sign();
	std::cin.get();
	test_too_low_to_execute();
	std::cin.get();
	test_execute();
	std::cin.get();
//	test_wrong_file_access();
	std::cout << std::endl;
	for(int i = 0; i < 4; i++)
	{
		test_robotomy();
		std::cin.get();
		std::cout << std::endl;

	}
	test_pardon_form();
	std::cin.get();
	test_bureaucrat_execute();
}

