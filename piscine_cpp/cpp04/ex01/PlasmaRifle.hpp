#ifndef INC_42_PLASMARIFLE_HPP
#define INC_42_PLASMARIFLE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "AWeapon.hpp"

class PlasmaRifle : public virtual AWeapon {
public:
				PlasmaRifle();
				PlasmaRifle(PlasmaRifle & T);
	virtual 	~PlasmaRifle();
	void 		attack() const;
				PlasmaRifle &operator=(const PlasmaRifle & T);
private:


};

#endif //INC_42_PLASMARIFLE_HPP
