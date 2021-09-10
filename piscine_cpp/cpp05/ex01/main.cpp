#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"


void 		test_instantiation(std::string name = "Contract", int sign = 150, int exec = 50)
{
	std::cout << "test instantiation (sign, exec) = "<< sign << " " << exec << std::endl;

	try
	{
		Form form(name, sign, exec);
		std::cout << "Success instantiating " << form;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception in <test_instantiation> : ";
		std::cout << e.what() << std::endl;
	}
}

void 		test_sign_form()
{
	std::cout << "test sign form" << std::endl;
	Bureaucrat bob("Bob", 30);
	Bureaucrat ted("Ted", 100);

	Form contract("Contract", 60, 100);

	try
	{
		contract.beSigned(ted);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		contract.beSigned(bob);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

}


int main()
{
	test_instantiation("Tax", 100, 30);
	std::cin.get();
	test_instantiation("Tax", 200, 30);
	std::cin.get();
	test_instantiation("Tax", 100, 0);
	std::cin.get();
	test_sign_form();
}

