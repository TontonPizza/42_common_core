#include <iostream>
#include <string>
#include <cstdlib>
#include "iter.hpp"
#include "rectangle.hpp"

void	display_rectangle(rectangle const & r) { std::cout << r << std::endl; }
void 	display_number(int const & a) { std::cout << "[" << a << "] " << std::endl; }

void	test_rectangle()
{
	rectangle a(4, 2);
	rectangle b(9, 3);
	rectangle rectangles[] = {a, b};
	iter(rectangles, 2, &display_rectangle);
}

void 	test_int()
{
	int numbers[] = {10, 8, 9, -1};
	iter(numbers, 4, &display_number);
}

int main()
{
	std::cout << "TEST display int array:" << std::endl;
	test_int();

	std::cin.get();
	std::cout << "TEST display custom class array :" << std::endl;
	test_rectangle();
}