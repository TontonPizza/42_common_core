#ifndef INC_42_RADSCORPION_HPP
#define INC_42_RADSCORPION_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Enemy.hpp"

class RadScorpion: public virtual Enemy {
public:
				RadScorpion();
				RadScorpion(RadScorpion & T);
	virtual 	~RadScorpion();
				RadScorpion & operator=(const RadScorpion & T);
	void 		takeDamage(int damage);
private:


};



#endif
