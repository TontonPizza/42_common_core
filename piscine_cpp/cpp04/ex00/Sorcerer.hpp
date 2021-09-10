#ifndef INC_42_SORCERER_HPP
#define INC_42_SORCERER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ostream>
#include "Victim.hpp"

class Sorcerer {
public:
						Sorcerer(std::string name, std::string title);
						Sorcerer(Sorcerer & T);
						~Sorcerer();
						Sorcerer &operator=(const Sorcerer & T);

	void 				polymorph(Victim const & T) const;
	std::string 		getName() const;
	std::string 		getTitle() const;

private:
						Sorcerer();
	std::string 		_name;
	std::string 		_title;
};

std::ostream & operator<<(std::ostream & os, const Sorcerer & T);

#endif //INC_42_SORCERER_HPP
