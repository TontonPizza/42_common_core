#include <string>
#include <iostream>
#include <cstdlib>

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "Enemy.hpp"

#include "JunkJet.hpp"
#include "Gulper.hpp"

void test_more_weapon()
{
	Character *benny = new Character("benny");

	benny->equip(new JunkJet());

	Enemy *fdp = new SuperMutant();

	while (fdp->getHP() > 0)
	{
		benny->attack(fdp);
		benny->recoverAP();
	}
}

void test_more_ennemies()
{
	Character *benny = new Character("benny");

	benny->equip(new JunkJet());

	Enemy *fdp = new Gulper();

	while (fdp->getHP() > 0)
	{
		benny->attack(fdp);
		benny->recoverAP();
	}
}

void tests_ap_limit()
{
	Character *bob = new Character("bob");
	bob->equip(new PowerFist());
	Enemy *sm = new SuperMutant();
	Enemy *sm2 = new SuperMutant();
	Enemy *rd = new RadScorpion();

	while (sm->getHP() > 0)
		bob->attack(sm);

	while (bob->getAP() < 40)
		bob->recoverAP();

	while (sm2->getHP() > 0)
		bob->attack(sm2);

	while (bob->getAP() < 40)
		bob->recoverAP();

	bob->equip(new PlasmaRifle());

	while (rd->getHP() > 0)
		bob->attack(rd);
}

int test_subject()
{

	Character* me = new Character("me");

	std::cout << *me;

	Enemy* b = new RadScorpion();

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();


	me->equip(pr);
	std::cout << *me;
	me->equip(pf);

	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	return (0);
}

int main()
{
	test_subject();
	std::cout << "----" << std::endl;
	test_more_weapon();
	std::cout << "----" << std::endl;
	test_more_ennemies();
	std::cout << "----" << std::endl;
	tests_ap_limit();
	std::cout << "----" << std::endl;
	test_more_weapon();


	return 0;
}