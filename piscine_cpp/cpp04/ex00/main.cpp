#include <string>
#include <iostream>
#include <cstdlib>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Dryade.hpp"


void test_derived_class()
{
	Sorcerer robert("Robert", "The Magnificient");

	Dryade dr("Lune");

	std::cout << robert << dr;

	robert.polymorph(dr);

	return;
}

int test_subject()
{
	Sorcerer robert("Robert", "The Magnificient");

	Victim jim("Jimmy");
	Peon   joe("Joe");

	std::cout << robert << jim << joe;

	robert.polymorph(jim);
	robert.polymorph(joe);

	return 0;
}


int main()
{
	test_subject();
	std::cout << "-----" << std::endl;
	test_derived_class();
}