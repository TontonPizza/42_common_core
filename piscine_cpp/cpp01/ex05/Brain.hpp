#ifndef PISCINE_CPP_BRAIN_HPP
#define PISCINE_CPP_BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>


class Brain {
public:
					Brain();
					~Brain();
	std::string 	identify() const;
private:
	std::string		_data;
};


#endif //PISCINE_CPP_BRAIN_HPP
