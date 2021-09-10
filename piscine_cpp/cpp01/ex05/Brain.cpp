#include "Brain.hpp"


Brain::Brain()
{
	int					i = 0;
	std::string			result;
	std::stringstream	convert;
	convert << this;
	convert >> result;
	while (result[i])
	{
		if (result[i] >= 'a' && result[i] <= 'z')
			result[i] += 'A' - 'a';
		i++;
	}
	this->_data = result;
}

Brain::~Brain()
{
	std::cout <<" brain destroyed" << std::endl;
}

std::string Brain::identify() const
{
	return _data;
}

