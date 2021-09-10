#include <string>
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"


void 		test_instantiation(std::string name = "Anon", int val = 150)
{
	std::cout << "TEST : instantiate Bureaucrat " << name << " grade " << val << std::endl;
	try
	{
		Bureaucrat bureaucrat(name, val);
		std::cout << "Success instantiating " << bureaucrat;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception in <test_instantiation> : ";
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void 		test_increase()
{
	std::cout << "TEST : increase grade to max " << std::endl;
	Bureaucrat bureaucrat("Luke", 150);

	while (bureaucrat.getGrade() > -1)
	{
		try
		{
			bureaucrat.incrementGrade(20);
			std::cout << bureaucrat;
		}
		catch (std::exception & e)
		{
			std::cout << "Exception in <test_increase> : ";
			std::cout << e.what() << std::endl;
			break;
		}
	}
	std::cout << std::endl;
}

void 	test_decrease()
{
	std::cout << "TEST : decrease grade to min " << std::endl;

	Bureaucrat bureaucrat("Luke", 1);

	while (bureaucrat.getGrade() < 150)
	{
		try
		{
			bureaucrat.decrementGrade(20);
			std::cout << bureaucrat;
		}
		catch (std::exception & e)
		{
			std::cout << "Exception in <test_decrease> : ";
			std::cout << e.what() << std::endl;
			break;
		}
	}
	std::cout << std::endl;

}

int main()
{
	test_instantiation();
	std::cin.get();
	test_instantiation("Joe", -1);
	std::cin.get();
	test_instantiation("Joe", 290);
	std::cin.get();
	test_increase();
	std::cin.get();
	test_decrease();

}

