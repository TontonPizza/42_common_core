#ifndef GIT_CPP_HUMANB_HPP
#define GIT_CPP_HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
public:
					HumanB(std::string name);
	void 			attack();
	void 			setWeapon(Weapon weapon);
private:
	std::string 	_name;
	Weapon			*_weapon;
};


#endif //GIT_CPP_HUMANA_HPP
