#ifndef INC_42_CHARACTER_HPP
#define INC_42_CHARACTER_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character {
public:
					Character(std::string const & name);
					Character(Character & T);
					~Character();
					Character &operator=(const Character & T);

	void 			recoverAP();
	void 			equip(AWeapon * wp);
	void 			attack(Enemy * enemy);

	std::string		getName() const;
	int				getAP() const;
	std::string 	getWeapon() const;

private:
					Character();
	std::string 	_name;
	int				_aP;
	AWeapon			*_weapon;
};

std::ostream 	& operator<<(std::ostream & os, const Character & T);


#endif //INC_42_CHARACTER_HPP
