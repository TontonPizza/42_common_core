#include "Pony.hpp"

Pony::Pony(std::string data):type(data)
{

}

Pony::~Pony()
{
	std::cout << "Pony on the " << this->type << " is no more :(" << std::endl;
}

void Pony::shine_you_magnificient_quadruped() const
{
	if (type == "stack")
	{
		std::cout << ",~~_" << std::endl;
		std::cout << "|/\\ =_ _ ~" << std::endl;
		std::cout << " _( )_( )\\~~    Crick Crack I'm the pony on the stack !" << std::endl;
		std::cout << " \\,\\  _|\\ \\~~~" << std::endl;
		std::cout << "    \\`   \\" << std::endl;
		std::cout << "    `    `" << std::endl;

	}
	else if (type == "heap")
	{
		std::cout << "                                                   .''" << std::endl;
		std::cout << "Zoup Zip I'm the pony on the heap !       ._.-.___.' (`\\" << std::endl;
		std::cout << "                                         //(        ( `'" << std::endl;
		std::cout << "                                       '/ )\\ ).__. ) " << std::endl;
		std::cout << "                                       ' <' `\\ ._/'\\" << std::endl;
		std::cout << "                                          `   \\     \\" << std::endl;
	}
}

