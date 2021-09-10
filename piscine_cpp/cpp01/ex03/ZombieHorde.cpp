#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N)
{
	this->_namePool[0] = 	"Lethum";
	this->_namePool[1] = 	"Wrouziuz";
	this->_namePool[2] = 	"Zrozius";
	this->_namePool[3] = 	"Oshothik";
	this->_namePool[4] = 	"Xovok";
	this->_type	= 			"pack";
	this->_nameCount = 		5;
	this->_count = N < 0 ? 0 : N;
	srand(time(0));
	this->_zombies = new Zombie[this->_count];            // <---------------- SINGLE ALLOCATION IS HERE
	for (int i = 0; i < this->_count; i++)
	{
		this->_zombies[i].setName(this->_namePool[rand() % this->_nameCount]);
		this->_zombies[i].setType(this->_type);
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] this->_zombies;                // <------------------- RELEASED AT DESTRUCTION
}

void ZombieHorde::announce() const
{
	for (int i = 0; i < this->_count ; i++)
	{
		this->_zombies[i].announce();
	}
}
