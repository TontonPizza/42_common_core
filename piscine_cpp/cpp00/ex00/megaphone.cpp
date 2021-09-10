#include <cstdlib>
#include <iostream>
#include "MegaString.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < argc; i ++)
	{
		MegaString	text = MegaString(argv[i]);
		text.display();
	}
	std::cout << std::endl;
	return (0);
}