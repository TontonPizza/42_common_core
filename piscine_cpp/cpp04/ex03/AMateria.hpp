#ifndef CPP04_AMATERIA_HPP
#define CPP04_AMATERIA_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include "ICharacter.hpp"

#define XP_PER_USE 10

class ICharacter;

class AMateria {

protected:
	unsigned int				xp;
	std::string 				type;
	void 						increaseXP();
	AMateria();
public:

										AMateria(std::string const & type);
										AMateria(const AMateria & T);
		virtual 						~AMateria();
		AMateria 						&operator=(const AMateria & T);

		std::string const & 			getType() const;
		unsigned int 					getXP() const;

		virtual AMateria*				clone() const = 0;
		virtual void 					use(ICharacter & target) = 0;

};



#endif //CPP04_AMATERIA_HPP
