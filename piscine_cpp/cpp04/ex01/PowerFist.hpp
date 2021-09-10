#ifndef INC_42_POWER_FIST_HPP
#define INC_42_POWER_FIST_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "AWeapon.hpp"

class PowerFist : public virtual AWeapon {
public:
				PowerFist();
				PowerFist(PowerFist & T);
	virtual 	~PowerFist();
	void 		attack() const;
				PowerFist &operator=(const PowerFist & T);
private:


};

#endif //INC_42_PLASMARIFLE_HPP
