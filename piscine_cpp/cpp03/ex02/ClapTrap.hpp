#ifndef INC_42_CPP_03_CLAPTRAP_HPP
#define INC_42_CPP_03_CLAPTRAP_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class ClapTrap {

protected:
	int 					_HP;
	int 					_maxHP;
	int 					_energyPoints;
	int						_maxEnergyPoint;
	int						_level;
	std::string			 	_name;
	std::string 			_type;
	int				 		_meleeAD;
	int				 		_rangedAD;
	int				 		_armor;
public:
			ClapTrap();
			~ClapTrap();
			ClapTrap(std::string name);
			ClapTrap &operator=(const ClapTrap & T);
	void	rangedAttack(std::string const &target);
	void 	meleeAttack(std::string const &target);
	void 	explosiveAttack(std::string const &target);
	void 	poisonAttack(std::string const &target);
	void 	thrustAttack(std::string const &target);

	void 	takeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);

private:

};

#endif //INC_42_CPP_03_CLAPTRAP_HPP
