#include "ISquad.hpp"
#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "UniversalSoldier.hpp"

#include <string>
#include <iostream>


void test_more_soldiers()
{
	Squad vlc;

	UniversalSoldier * b = new UniversalSoldier;

	vlc.push(b);
	vlc.getUnit(0)->battleCry();
}

void test_add_illegal_element()
{
	Squad vlc;

	TacticalMarine*b = new TacticalMarine;

	vlc.push(b);
	vlc.push(b);
	vlc.push(NULL);

	std::cout << vlc.getCount() << std::endl;
}



void test_copy()
{
	Squad vlc;

	TacticalMarine *b = new TacticalMarine;
	ISpaceMarine* c = new AssaultTerminator;

	vlc.push(b);
	vlc.push(c);


	vlc.getUnit(1)->battleCry();

	Squad  vlc2(vlc);

	std::cout << vlc.getCount() << std::endl;
	std::cout << vlc2.getCount() << std::endl;
}

void test_subject()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;

	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);

	for (int i = 0; i < vlc->getCount(); i++)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	delete vlc;

}

int main()
{
	test_more_soldiers();
	std::cout << "-----" << std::endl;
	test_add_illegal_element();
	std::cout << "-----" << std::endl;
	test_copy();
	std::cout << "-----" << std::endl;
	test_subject();
	std::cout << "-----" << std::endl;

	return (0);
}
