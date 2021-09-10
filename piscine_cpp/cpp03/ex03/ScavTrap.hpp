#ifndef INC_42_CPP_03_SCAVTRAP_HPP
#define INC_42_CPP_03_SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class ScavTrap : public ClapTrap {
public:
					ScavTrap();
					ScavTrap(std::string data);
					ScavTrap(ScavTrap & T);
					~ScavTrap();
					ScavTrap &operator=(const ScavTrap & T);

	void 			challengeDDR(std::string const & target);
	void 			challengeChineseFeast(std::string const & target);
	void 			challengeNewcomer(std::string const & target);


private:
	int 					_HP;
	const static int 		_maxHP = 100;
	int 					_energyPoints;
	const static int		_maxEnergyPoint = 50;
	int						_level;
	std::string			 	_name;
	const static int 		_meleeAD = 20;
	const static int 		_rangedAD = 15;
	const static int 		_armor = 3;

	void 			initAttackPool();
	void (ScavTrap::*challengePool[2])(std::string const &);
};


#endif //INC_42_CPP_03_SCAVTRAP_HPP
