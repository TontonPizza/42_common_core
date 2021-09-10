#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator & T)
{
	T.doNothing();
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(const AssaultTerminator & T)
{
	T.doNothing();
	return (*this);
}

////////////:

AssaultTerminator * AssaultTerminator::clone() const
{
	AssaultTerminator * b = new AssaultTerminator();
	return b;
}

void 			AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void 			AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *" << std::endl;
}

void 			AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *" << std::endl;
}

void 			AssaultTerminator::doNothing() const
{
	return ;
}
