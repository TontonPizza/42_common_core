#ifndef CPP04_ICE_HPP
#define CPP04_ICE_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "AMateria.hpp"

class Ice: public  virtual AMateria {
public:
							Ice();
							Ice(unsigned int xp);
							Ice(const Ice & T);
	virtual					~Ice();
							Ice &operator=(const Ice & T);

	std::string const & 	getType() const;
	unsigned int 			getXP() const;
	AMateria *				clone() const;
	void 					use(ICharacter & target);

private:
	void 					increaseXP();
	void					copyXP(const Ice & T);
};



#endif //CPP04_ICE_HPP
