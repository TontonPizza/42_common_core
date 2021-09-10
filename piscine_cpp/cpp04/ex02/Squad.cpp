#include "Squad.hpp"

Squad::Squad()
{
	this->_count = 0;
	this->_unitPtr = NULL;
}

Squad::Squad(Squad & T)
{
	if (this == &T)
		return ;
	this->_count = 0;
	this->_unitPtr = NULL;
	copyUnits(T._unitPtr);
}

Squad::~Squad()
{
	destroyUnits(this->_unitPtr);
}

Squad & Squad::operator=(const Squad & T)
{
	if (this == &T)
		return (*this);
	this->_count = 0;
	this->destroyUnits(this->_unitPtr);
	copyUnits(T._unitPtr);
	return (*this);
}

int 		Squad::getCount() const
{
	return this->_count;
}

ISpaceMarine * 	Squad::getUnit(int n) const
{
	t_unit *current;

	if (n >= this->getCount())
		return (NULL);
	current = this->_unitPtr;
	while (n--)
		current = current->next;
	return (current->unit);
}

int 			Squad::push(ISpaceMarine * T)
{
	t_unit *current;
	t_unit *unitToAdd;

	current = this->_unitPtr;
	if (T == NULL)
		return (this->getCount());
	while (current != NULL)
	{
		if (current->unit == T)
			return (this->getCount());
		if (current->next == NULL)
			break;
		current = current->next;
	}
	unitToAdd= new t_unit();
	unitToAdd->unit = T;
	unitToAdd->next = NULL;
	if (current == NULL)
		this->_unitPtr = unitToAdd;
	else
		current->next = unitToAdd;
	this->incrementCount();
	return (getCount());
}

void			Squad::destroyUnits(t_unit *ptr)
{
	if (ptr == NULL)
		return;
	destroyUnits(ptr->next);
	delete (ptr->unit);
	delete (ptr);
}

void			Squad::copyUnits(t_unit *source)
{
	t_unit *current;

	current = source;
	while (current)
	{
		this->push(current->unit->clone());
		current = current->next;
	}
}

void 			Squad::incrementCount()
{
	this->_count = this->_count + 1;
}