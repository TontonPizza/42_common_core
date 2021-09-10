#ifndef CPP04_Bahamut_HPP
#define CPP04_Bahamut_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "AMateria.hpp"

class Bahamut: public  virtual AMateria {
public:
							Bahamut();
							Bahamut(unsigned int xp);
							Bahamut(const Bahamut & T);
	virtual					~Bahamut();
	Bahamut &operator=(const Bahamut & T);

	std::string const & 	getType() const;
	unsigned int 			getXP() const;
	AMateria *				clone() const;
	void 					use(ICharacter & target);

private:
	void 					increaseXP();
	void					copyXP(const Bahamut & T);
};



#endif //CPP04_ICE_HPP
