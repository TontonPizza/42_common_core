#ifndef CPP03_FRAGTRAP_HPP
#define CPP03_FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class FragTrap : public virtual ClapTrap{
public:
					FragTrap();
					FragTrap(std::string data);
					FragTrap(FragTrap & T);
					~FragTrap();
					FragTrap &operator=(const FragTrap & T);

	void 			vaulthunter_dot_exe(std::string const & target);

protected:
	int 					_HP;
	const static int 		_maxHP = 100;
	int 					_energyPoints;
	const static int		_maxEnergyPoint = 100;
	int						_level;
	std::string			 	_name;
	const static int 		_meleeAD = 30;
	const static int 		_rangedAD = 20;
	const static int 		_armor = 5;

	void 			initAttackPool();
	void (ClapTrap::*attackPointers[5])(std::string const &);
};


#endif //CPP03_FRAGTRAP_HPP
