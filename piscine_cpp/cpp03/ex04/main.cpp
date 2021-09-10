#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "SuperTrap.hpp"
#include <iostream>
#include <string>

int main()
{

	ScavTrap  scav;
	SuperTrap sp("super");


	sp.ninjaShoebox(scav);
	sp.vaulthunter_dot_exe("me");
	sp.rangedAttack("pouet");
	sp.meleeAttack("plop");
	sp.rangedAttack("plouic");
}