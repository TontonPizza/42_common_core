#ifndef GIT_CPP_PONY_HPP
#define GIT_CPP_PONY_HPP

#include <iostream>
#include <string>

class Pony {
public:
					Pony(std::string type);
					~Pony();
	void 			shine_you_magnificient_quadruped() const;
private:
	std::string		type;
};


#endif //GIT_CPP_PONY_HPP
