#ifndef INC_42_UniversalSoldier_HPP
#define INC_42_UniversalSoldier_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "ISpaceMarine.hpp"


class UniversalSoldier: public virtual ISpaceMarine {
public:
							UniversalSoldier();
							UniversalSoldier(UniversalSoldier & T);
	virtual 				~UniversalSoldier();
	UniversalSoldier 		&operator=(const UniversalSoldier & T);
	void 					doNothing() const;

	UniversalSoldier *  	clone() const;
	void 					battleCry() const;
	void 					rangedAttack() const;
	void 					meleeAttack() const ;
};


#endif //INC_42_UniversalSoldier_HPP
