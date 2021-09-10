#include "Human.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

int main()
{
	Human		bob;

	std::cout << bob.identify() << std::endl;
	std::cout << bob.getBrain().identify() << std::endl;
}