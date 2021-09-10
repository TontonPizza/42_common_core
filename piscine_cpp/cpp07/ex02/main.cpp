#include <iostream>
#include <string>
#include <cstdlib>
#include "Array.hpp"

void	test_empty()
{
	std::cout << "TEST EMPTY : " << std::endl;
	Array<int> arr(0);
	std::cout << arr.size() << std::endl;
	std::cin.get();
}

void 	test_basic_usage()
{
	std::cout << "TEST BASIC USAGE : " << std::endl;
	Array<int> arr(3);
	arr[0] = 1;
	arr[1] = 9;
	arr[2] = 5;
	std::cout << arr[0] << "," << arr[1] << "," << arr[2] << "," << std::endl;
	std::cin.get();
}

void 	test_out_of_range()
{
	std::cout << "TEST OUT OF RANGE INDEX :" << std::endl;
	Array<int> arr(4);

	try
	{
		std::cout << arr[9] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cin.get();
}

void	test_copy()
{
	std::cout << "TEST COPY : " << std::endl;
	Array<std::string> original(2);
	original[0] = std::string("salut");
	original[1] = std::string("pouet");
	Array<std::string> copy(original);

	std::cout << "original : " << original[0] << ", " << original[1] << std::endl;
	std::cout << "copy : " << copy[0] << ", " << copy[1] << std::endl << std::endl;
	std::cin.get();
	std::cout << "modification original : " << std::endl;
	original[0] = std::string("zut");
	std::cout << "original[0] = " << original[0] << std::endl;
	std::cout << "copy[0] = " << copy[0] << std::endl << std::endl;
	std::cin.get();
	std::cout << "modification copy : " << std::endl;
	copy[1] = std::string("tralala");
	std::cout <<  "original[1] = " << original[1] << std::endl;
	std::cout << "copy[1] = " << copy[1] << std::endl;
	std::cin.get();
}

int main()
{
	test_basic_usage();
	test_empty();
	test_out_of_range();
	test_copy();
}