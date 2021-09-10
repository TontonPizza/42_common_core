#include "Pony.hpp"
#include <iostream>
#include <string>

void ponyOnTheHeap()
{
	Pony *pony = new Pony("heap");
	pony->shine_you_magnificient_quadruped();
	delete pony;
}

void ponyOnTheStack()
{
	Pony pony = Pony("stack");
	pony.shine_you_magnificient_quadruped();
}

int main()
{
	std::cout << "MAIN() ---- before pony on the heap ----" << std::endl;
	ponyOnTheHeap();
	std::cout << "MAIN() ---- after pony on the heap  ----" << std::endl;

	std::cout << std::endl << std::endl ;

	std::cout << "MAIN() ---- before pony on the stack ----" << std::endl;
	ponyOnTheStack();
	std::cout << "MAIN() ---- after pony on the stack  ----" << std::endl;
}