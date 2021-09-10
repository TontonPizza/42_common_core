#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i ++)
		this->source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource & T)
{
	*this = T;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->source[i] != NULL)
			delete this->source[i];
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource & T)
{
	for (int i = 0; i < 4; i++)
	{
		if (T.source[i])
			this->source[i] = T.source[i]->clone();
		else
			this->source[i] = NULL;
	}
	return (*this);
}

void 			MateriaSource::learnMateria(AMateria *T)
{
	int i = 0;
	while (i < 4)
	{
		if (this->source[i] == NULL)
		{
			this->source[i] = T->clone();
			break;
		}
		i++;
	}
}

AMateria *		MateriaSource::createMateria(const std::string &type)
{
	int i = 0;
	while (i < 4)
	{
		if (this->source[i] && this->source[i]->getType() == type)
		{
			return this->source[i]->clone();
		}
		i++;
	}
	return (NULL);
}