#ifndef CPP04_CURE_HPP
#define CPP04_CURE_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "AMateria.hpp"

class Cure: public  virtual AMateria {
public:
							Cure();
							Cure(unsigned int xp);
							Cure(const Cure & T);
	virtual					~Cure();
							Cure &operator=(const Cure & T);

	std::string const & 	getType() const;
	unsigned int 			getXP() const;
	AMateria *				clone() const;
	void 					use(ICharacter & target);

private:
	void 					increaseXP();
	void					copyXP(const Cure & T);
};



#endif //CPP04_ICE_HPP
