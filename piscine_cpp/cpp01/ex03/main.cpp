#include "Zombie.hpp"
#include "ZombieHorde.hpp"
#include <string>
#include <iostream>

int main()
{
	ZombieHorde zombieHorde = ZombieHorde(5);

	zombieHorde.announce();
}