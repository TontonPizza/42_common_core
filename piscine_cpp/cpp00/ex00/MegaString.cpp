#include <iostream>
#include "MegaString.hpp"

MegaString::MegaString(char *input) : text(input) // At instanciation, put the input in CAPITAL LETTER
{
	int 	i;

	i = 0;
	while (this->text[i])
	{
		if (this->text[i] >= 'a' && this->text[i] <= 'z')
			this->text[i] += 'A' - 'a';
		i++;
	}
	return ;
}

MegaString::~MegaString(void) // Do nothing
{
	return ;
}

void	MegaString::display(void) const // Display the attribute : text
{
	std::cout << (this->text) << " ";
	return ;
}
