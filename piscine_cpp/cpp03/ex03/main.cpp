#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main()
{

	ClapTrap cp("clap");
	FragTrap fp("frag");
	ScavTrap sp("scav");


	NinjaTrap np("ninja");


	np.ninjaShoebox(cp);
	np.ninjaShoebox(fp);
	np.ninjaShoebox(sp);
	np.ninjaShoebox(np);

}