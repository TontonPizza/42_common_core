#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main()
{

	FragTrap *a;
	a = new FragTrap("ted");

	a->vaulthunter_dot_exe("vim");
	a->vaulthunter_dot_exe("emacs");
	a->vaulthunter_dot_exe("nano");
	a->vaulthunter_dot_exe("vs-code");
	a->vaulthunter_dot_exe("code-blocks");
	a->vaulthunter_dot_exe("rubymine");

	a->meleeAttack("FDP");
	a->takeDamage(25);
	a->takeDamage(1);
	a->takeDamage(0);
	a->takeDamage(100);
	a->beRepaired(60);
	a->beRepaired(120);
//	delete a;

	std::cout << std::endl <<"____________________________________" << std::endl << std::endl;

	ScavTrap *s;
	s = new ScavTrap("bed");
	s->challengeNewcomer("MIKEY");
	s->challengeNewcomer("MIKEY");
	s->challengeNewcomer("MIKEY");
	s->challengeNewcomer("MIKEY");
	s->meleeAttack("BOB");
	s->beRepaired(2);
	s->takeDamage(40);
	s->rangedAttack("JIM");

	delete s;
}