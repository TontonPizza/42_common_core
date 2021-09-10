#include <iomanip>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"


int main()
{

//	std::cout << std::setfill('-') << std::setw(100) << " [Proof that the ref points to the type]" << std::endl;
//	Weapon weapon = Weapon("blade");
//	std::cout << std::setfill('-') << std::setw(100) << " [Creating a weapon. declaring a ref to its type and printing it :]" <<std::endl;
//	std::string& refType = weapon.getType();
//	std::cout << refType << std::endl;
//	std::cout << std::setfill('-') << std::setw(100) << " [change type with setType and printing the same ref]" << std::endl;
//	weapon.setType("electric");
//	std::cout << refType << std::endl;
//	std::cout << std::setfill('-') << std::setw(100) << " [QED]" << std::endl << std::endl;


	{
		Weapon club = Weapon("crude spiked club");

		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");

		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}




}