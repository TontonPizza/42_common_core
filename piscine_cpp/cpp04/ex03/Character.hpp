#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "ICharacter.hpp"

class Character: public virtual ICharacter {
public:
						Character();
						Character(std::string name);
						Character(const Character & T);
	virtual				~Character();
						Character &operator=(const Character & T);
	void 				equip(AMateria * m);
	void 				unequip(int idx);
	void 				use(int idx, ICharacter & target);
	std::string const &	getName() const;
private:
	AMateria*			materias[4];
	std::string 		name;
	void				deleteMaterias();
	void				copyMaterias(const Character & T);
};


#endif //CPP04_CHARACTER_HPP
