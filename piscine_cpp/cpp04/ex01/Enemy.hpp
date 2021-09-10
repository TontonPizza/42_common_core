#ifndef INC_42_ENEMY_HPP
#define INC_42_ENEMY_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Enemy {
public:
					Enemy(int hp, std::string const & type);
					Enemy(Enemy & T);
	virtual 		~Enemy();
	std::string		getType() const;
	int 			getHP() const;
					Enemy &operator=(const Enemy & T);
	virtual void 	takeDamage(int damage);
protected:
	int 			_hP;
	std::string 	_type;
					Enemy();

};



#endif //INC_42_ENEMY_HPP
