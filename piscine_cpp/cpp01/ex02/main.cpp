#include <iostream>
#include <string>
#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main()
{
	std::cout << std::endl;
	std::cout << "------------- Generating zombies on the HEAP" << std::endl;
	ZombieEvent zombieManager = ZombieEvent();

	Zombie* heapZombie = zombieManager.newZombie("main_Zombie_1");
	heapZombie->announce();
	delete heapZombie;

	zombieManager.setZombieType("fire");
	heapZombie = zombieManager.newZombie("main_Zombie_2");
	heapZombie->announce();
	delete heapZombie;
	std::cout << "--------------------------------------- DONE" << std::endl << std::endl;

	std::cout << "------ Generating RANDOM zombie on the STACK" << std::endl;
	zombieManager.setZombieType("biter");
	zombieManager.randomChump();
	zombieManager.setZombieType("brooder");
	zombieManager.randomChump();
	std::cout << "--------------------------------------- DONE" << std::endl;


}