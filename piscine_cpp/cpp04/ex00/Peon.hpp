#ifndef INC_42_PEON_HPP
#define INC_42_PEON_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "Victim.hpp"

class Peon : public virtual Victim {
public:
					Peon(Peon & T);
					Peon(std::string name);
	virtual 		~Peon();
					Peon &operator=(const Peon & T);
	void 			getPolymorphed() const;
private:
					Peon();
	std::string		_name;
};



#endif //INC_42_PEON_HPP
