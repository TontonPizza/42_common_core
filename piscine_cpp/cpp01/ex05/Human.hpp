#include "Brain.hpp"

#ifndef PISCINE_CPP_HUMAN_HPP
#define PISCINE_CPP_HUMAN_HPP


class Human {
public:
	std::string 	identify();
	const Brain 	& getBrain() const;
private:
	Brain	const	_brain;
};


#endif //PISCINE_CPP_HUMAN_HPP
