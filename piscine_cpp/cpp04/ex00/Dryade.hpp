#ifndef INC_42_DRYADE_HPP
#define INC_42_DRYADE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Victim.hpp"

class Dryade : public virtual Victim {
public:
				Dryade(Dryade & T);
				Dryade(std::string name);
	virtual 	~Dryade();
	Dryade 		&operator=(const Dryade & T);
	void 		getPolymorphed() const;
private:
	Dryade();
	std::string	_name;
};



#endif