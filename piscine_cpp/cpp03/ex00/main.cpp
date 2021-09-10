#include "FragTrap.hpp"
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

	a->takeDamage(25);
	a->takeDamage(1);
	a->takeDamage(0);
	a->takeDamage(100);
	a->beRepaired(60);
	a->beRepaired(120);
	delete a;

	FragTrap b;
	b = FragTrap("joe");
	b.poisonAttack("emacs");

}