#ifndef PISCINE_CPP_ZOMBIE_HPP
#define PISCINE_CPP_ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
public:
					Zombie();
					Zombie(std::string type, std::string name);
					~Zombie();
	void 			announce() const;
	void 			setName(std::string name);
	void 			setType(std::string type);
private:
	std::string		_type;
	std::string		_name;
};


#endif //PISCINE_CPP_ZOMBIE_HPP
