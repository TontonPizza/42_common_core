#include "Character.hpp"


Character::Character()
{

}

Character::Character(std::string name): name(name)
{
	for (int i = 0; i < 4 ; i++)
		this->materias[i] = NULL;
}

Character::Character(const Character & T)
{
	this->deleteMaterias();
	this->copyMaterias(T);
}

Character::~Character()
{
	this->deleteMaterias();
}

Character & Character::operator=(const Character & T)
{
	this->deleteMaterias();
	this->copyMaterias(T);
	this->name = T.getName();
	return (*this);
}

std::string	const &	Character::getName() const
{
	return (this->name);
}

void			Character::deleteMaterias()
{
	for (int i = 0; i < 4; i ++)
	{
		if (this->materias[i] != NULL)
		{
			delete this->materias[i];
			this->materias[i] = NULL;
		}
	}
}

void			Character::copyMaterias(const Character & T)
{
	for(int i = 0; i < 4; i++)
	{
		this->materias[i] = NULL;
		if (T.materias[i])
			this->materias[i] = T.materias[i]->clone();
	}
}

void			Character::equip(AMateria *m)
{
	for (int i = 0; i < 3; i++)
	{
		if (this->materias[i] == m)
			return ;
		if (this->materias[i] == NULL)
		{
			this->materias[i] = m;
			return;
		}
	}
}

void 			Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	this->materias[idx] = NULL;
}

void			Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || materias[idx] == NULL)
		return ;
	this->materias[idx]->use(target);
}