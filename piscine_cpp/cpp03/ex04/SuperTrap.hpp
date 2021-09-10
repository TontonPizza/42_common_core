#ifndef INC_42_CPP_03_SUPERTRAP_HPP
#define INC_42_CPP_03_SUPERTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include <string>
#include <iostream>

class SuperTrap: public FragTrap, public NinjaTrap {
public:
				SuperTrap();
				SuperTrap(std::string name);
				SuperTrap(SuperTrap & T);
				~SuperTrap();
				SuperTrap &operator=(const SuperTrap & T);
				void meleeAttack(std::string const & target);
				void rangedAttack(std::string const & target);
private:
	std::string 	_name;

};



#endif //INC_42_CPP_03_SUPERTRAP_HPP
