#ifndef INC_42_AWEAPON_HPP
#define INC_42_AWEAPON_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class AWeapon {
public:
					AWeapon(std::string const & name, int apcost, int damage);
					AWeapon(AWeapon & T);
	virtual 		~AWeapon();
					AWeapon &operator=(const AWeapon & T);

	int				getAPCost() const;
	int 			getDamage() const;
	std::string 	getName() const;
	void 			virtual attack() const = 0;

protected:
	std::string 	_name;
	int 			_aPCost;
	int 			_damagePoint;
	AWeapon();


};



#endif //INC_42_AWEAPON_HPP
