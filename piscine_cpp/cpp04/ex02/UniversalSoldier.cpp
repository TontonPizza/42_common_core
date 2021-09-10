#include "UniversalSoldier.hpp"

UniversalSoldier::UniversalSoldier()
{
	std::cout << "I m the best figher in the world" << std::endl;
}

UniversalSoldier::UniversalSoldier(UniversalSoldier & T)
{
	T.doNothing();
}

UniversalSoldier::~UniversalSoldier()
{
	std::cout << "Avenge me" << std::endl;
}

UniversalSoldier & UniversalSoldier::operator=(const UniversalSoldier & T)
{
	T.doNothing();
	return (*this);
}

////////////:

UniversalSoldier * UniversalSoldier::clone() const
{
	UniversalSoldier * b = new UniversalSoldier();
	return b;
}

void 			UniversalSoldier::battleCry() const
{
	std::cout << "Eliminate" << std::endl;
}

void 			UniversalSoldier::meleeAttack() const
{
	std::cout << "* attacks with knife *" << std::endl;
}

void 			UniversalSoldier::rangedAttack() const
{
	std::cout << "* snipe from distance *" << std::endl;
}

void 			UniversalSoldier::doNothing() const
{
	return ;
}
