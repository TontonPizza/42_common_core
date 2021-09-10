#ifndef INC_42_VICTIM_HPP
#define INC_42_VICTIM_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <cstdlib>

class Victim {
public:
						Victim(Victim & T);
						Victim(std::string name);
	virtual 			~Victim();
						Victim &operator=(const Victim & T);
	std::string 		getName() const;
	void virtual		getPolymorphed() const;

protected:
						Victim();
	std::string 		_name;
};

std::ostream & operator<<(std::ostream & os, const Victim & T);

#endif //INC_42_VICTIM_HPP
