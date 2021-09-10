#include "ZombieEvent.hpp"



ZombieEvent::ZombieEvent()
{
	this->_namePool[0] = 	"Lethum";
	this->_namePool[1] = 	"Wrouziuz";
	this->_namePool[2] = 	"Zrozius";
	this->_namePool[3] = 	"Oshothik";
	this->_namePool[4] = 	"Xovok";
	this->_type	= 			"vanilla";
	this->_nameCount = 		5;
	srand(time(0));
}

ZombieEvent::~ZombieEvent()
{

}

void	ZombieEvent::randomChump()
{
	std::string _randomName = this->_namePool[rand() % this->_nameCount];
	Zombie	zombie = Zombie(this->_type, _randomName);
	zombie.announce();
}

Zombie * ZombieEvent::newZombie(std::string name)
{
	return (new Zombie(this->_type, name));
}

void ZombieEvent::setZombieType(std::string type)
{
	this->_type = type;
}