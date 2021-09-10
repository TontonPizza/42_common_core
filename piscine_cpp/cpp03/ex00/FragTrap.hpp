#ifndef CPP03_FRAGTRAP_HPP
#define CPP03_FRAGTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class FragTrap {
public:
					FragTrap();
					FragTrap(std::string data);
					FragTrap(FragTrap & T);
					~FragTrap();
					FragTrap &operator=(const FragTrap & T);

	void 			rangedAttack(std::string const & target);
	void 			meleeAttack(std::string const & target);
	void 			explosiveAttack(std::string const & target);
	void 			poisonAttack(std::string const & target);
	void 			thrustAttack(std::string const & target);

	void 			takeDamage(unsigned int amount);
	void 			beRepaired(unsigned int amount);

	void 			vaulthunter_dot_exe(std::string const & target);

private:
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
	void (FragTrap::*attackPointers[5])(std::string const &);
};


#endif //CPP03_FRAGTRAP_HPP
