#ifndef INC_42_SUPERMUTANT_HPP
#define INC_42_SUPERMUTANT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Enemy.hpp"

class SuperMutant: public virtual Enemy {
public:
				SuperMutant();
				SuperMutant(SuperMutant & T);
	virtual 	~SuperMutant();
				SuperMutant & operator=(const SuperMutant & T);
	void 		takeDamage(int damage);
private:


};



#endif //INC_42_SUPERMUTANT_HPP
