#ifndef PISCINE_CPP_ZOMBIEHORDE_HPP
#define PISCINE_CPP_ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <cstdlib>

class ZombieHorde {
public:
					ZombieHorde(int N);
					~ZombieHorde();
	void 			announce() const;
private:
	int 			_count;
	int 			_nameCount;
	std::string 	_namePool[5];
	std::string 	_type;
	Zombie*			_zombies;
};


#endif //PISCINE_CPP_ZOMBIEHORDE_HPP
