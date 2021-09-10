#ifndef CPP04_MATERIASOURCE_HPP
#define CPP04_MATERIASOURCE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "IMateriaSource.hpp"

class MateriaSource : public virtual IMateriaSource{
public:
						MateriaSource();
						MateriaSource(const MateriaSource & T);
			virtual		~MateriaSource();
						MateriaSource &operator=(const MateriaSource & T);

			void		learnMateria(AMateria * T);
			AMateria * createMateria(std::string const & type);
private:

	AMateria * source[4];

};


#endif //CPP04_MATERIASOURCE_HPP
