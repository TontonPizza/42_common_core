#ifndef INC_42_ASSAULTTERMINATOR_HPP
#define INC_42_ASSAULTTERMINATOR_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "ISpaceMarine.hpp"


class AssaultTerminator: public virtual ISpaceMarine {
public:
						AssaultTerminator();
						AssaultTerminator(AssaultTerminator & T);
	virtual 			~AssaultTerminator();
	AssaultTerminator 	&operator=(const AssaultTerminator & T);
	void 				doNothing() const;

	AssaultTerminator * clone() const;
	void 				battleCry() const;
	void 				rangedAttack() const;
	void 				meleeAttack() const ;
};


#endif //INC_42_ASSAULTTERMINATOR_HPP
