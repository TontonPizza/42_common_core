#ifndef INC_42_Gulper_HPP
#define INC_42_Gulper_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Enemy.hpp"

class Gulper: public virtual Enemy {
public:
				Gulper();
				Gulper(Gulper & T);
	virtual 	~Gulper();
	Gulper 		& operator=(const Gulper & T);
	void 		takeDamage(int damage);
private:


};



#endif
