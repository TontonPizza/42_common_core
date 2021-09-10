#ifndef GIT_CPP_WEAPON_HPP
#define GIT_CPP_WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
public:
							explicit Weapon(std::string data);
							~Weapon();
	const std::string &		getType() const;
	void 					setType(std::string type);
private:
	std::string &			_refType;
	std::string				_type;
};


#endif //GIT_CPP_WEAPON_HPP
