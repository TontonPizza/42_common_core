#include <iostream>
#include <string>
#include <cstdlib>
#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Bahamut.hpp"

void test_xp()
{
	Character ben("ben");

	AMateria	*icy = new Ice();
	ben.equip(icy);
	ben.use(0, ben);
	std::cout << icy->getXP() << " " << icy->getType() << std::endl;
	ben.use(0, ben);
	std::cout << icy->getXP() << " " << icy->getType() << std::endl;
	ben.use(0, ben);
	std::cout << icy->getXP() << " " << icy->getType() << std::endl;
	ben.use(0, ben);
	std::cout << icy->getXP() << " " << icy->getType() << std::endl;
}

void	test_inventory()
{
	Character ben("ben");
	AMateria	*icy = new Ice();
	AMateria	*cure= new Cure();

	ben.equip(icy);

	ben.equip(icy);
	ben.equip(icy);
	ben.equip(icy);
	ben.equip(NULL);

	ben.equip(cure);

	ben.use(0, ben);
	ben.use(1, ben);
	ben.use(6, ben);

	ben.unequip(1);
	ben.use(1, ben);
	ben.equip(cure);
	ben.use(1, ben);
}

void test_copy_char()
{
	Character luke("Luke");
	AMateria	*ice2 = new Ice();

	luke.equip(ice2);

	Character joe(luke);
	joe.use(0, luke);
	std::cout << ice2->getXP() << std::endl;


}

void 	test_more_materia()
{
	Character ben("ben");
	AMateria	*bm = new Bahamut();

	ben.equip(bm);

	ben.use(0, ben);
}

void 	test_subject()
{
	IMateriaSource * src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter * me = new Character("me");

	AMateria * tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter * bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return;
}

int main()
{

	test_copy_char();
	std::cout << "---" << std::endl;
	test_inventory();
	std::cout << "---" << std::endl;
	test_more_materia();
	std::cout << "---" << std::endl;
	test_subject();
	std::cout << "---" << std::endl;
	test_xp();
}