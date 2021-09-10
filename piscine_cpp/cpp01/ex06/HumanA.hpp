#ifndef GIT_CPP_HUMANA_HPP
#define GIT_CPP_HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
public:
					HumanA(std::string name, Weapon & weapon);
	void 			attack();
private:
	std::string 	_name;
	Weapon &		_weapon;
};


#endif //GIT_CPP_HUMANA_HPP
