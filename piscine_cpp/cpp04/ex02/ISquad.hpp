#ifndef CPP04_ISQUAD_HPP
#define CPP04_ISQUAD_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "ISpaceMarine.hpp"


class ISquad {
public:
	virtual					~ISquad() { }
	virtual int 			getCount() const = 0;
	virtual ISpaceMarine * 	getUnit(int n) const = 0;
	virtual int 			push(ISpaceMarine * T) = 0;
};


#endif //CPP04_ISQUAD_HPP
