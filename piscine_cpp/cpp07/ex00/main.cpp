#include <iostream>
#include <string>
#include <cstdlib>
#include "templates.hpp"
#include "rectangle.hpp"

void	test_class()
{
	rectangle a(10, 3);
	rectangle b(5, 8);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
}

void 	test_subject()
{
	int a = 2;
	int b = 3;

	::swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

}

int main()
{
	std::cout << "TEST SUBJECT : " << std::endl;
	test_subject();

	std::cin.get();
	std::cout << "TEST CUSTOM CLASS :" << std::endl;
	test_class();
}