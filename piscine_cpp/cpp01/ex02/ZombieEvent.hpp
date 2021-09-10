#ifndef PISCINE_CPP_ZOMBIEEVENT_HPP
#define PISCINE_CPP_ZOMBIEEVENT_HPP

#include <cstdlib>
#include "Zombie.hpp"
#include <iostream>
#include <string>

class ZombieEvent {
public:
					ZombieEvent();
					~ZombieEvent();
	void 			setZombieType(std::string type);
	Zombie*			newZombie(std::string name);
	void 			randomChump();
private:
	std::string 	_type;
	int 			_nameCount;
	std::string 	_namePool[5];
};


#endif //PISCINE_CPP_ZOMBIEEVENT_HPP
