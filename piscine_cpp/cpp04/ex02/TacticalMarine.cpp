#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine & T)
{
		T.doNothing();
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaarg..." << std::endl;
}

TacticalMarine & TacticalMarine::operator=(const TacticalMarine & T)
{
	T.doNothing();
	return (*this);
}

////////////:

TacticalMarine * TacticalMarine::clone() const
{
	TacticalMarine * b = new TacticalMarine();
	return b;
}

void 			TacticalMarine::battleCry() const
{
		std::cout << "For the holy PLOT" << std::endl;
}

void 			TacticalMarine::rangedAttack() const
{
		std::cout << "* attacks with a bolter *" << std::endl;
}

void 			TacticalMarine::meleeAttack() const
{
		std::cout << "* attacks with a chainsword *" << std::endl;
}

void 			TacticalMarine::doNothing() const
{
	return ;
}