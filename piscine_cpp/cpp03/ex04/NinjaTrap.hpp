#ifndef INC_42_CPP_03_NINATRAP_HPP
#define INC_42_CPP_03_NINATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

class NinjaTrap: public virtual ClapTrap  {
public:
				NinjaTrap();
				NinjaTrap(std::string name);
				NinjaTrap(NinjaTrap & T);
				~NinjaTrap();
				NinjaTrap &operator=(const NinjaTrap & T);
	void		ninjaShoebox(ScavTrap & T);
	void 		ninjaShoebox(FragTrap & T);
	void 		ninjaShoebox(NinjaTrap & T);
	void 		ninjaShoebox(ClapTrap & T);
protected:

	int 					_HP;
	const static int 		_maxHP = 60;
	int 					_energyPoints;
	const static int		_maxEnergyPoint = 120;
	int						_level;
	std::string			 	_name;
	const static int 		_meleeAD = 60;
	const static int 		_rangedAD = 5;
	const static int 		_armor = 0;
};



#endif //INC_42_CPP_03_NINATRAP_HPP
