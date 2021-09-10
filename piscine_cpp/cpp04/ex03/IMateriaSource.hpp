#ifndef IMATERIA_MATERIA_SOURCE_HPP
# define IMATERIA_MATERIA_SOURCE_HPP

#include "AMateria.hpp"
class AMateria;

class IMateriaSource
{
public :
		virtual ~IMateriaSource(){}
		virtual void learnMateria(AMateria * T) = 0;
		virtual AMateria * createMateria(std::string const & type) = 0;
};

#endif
