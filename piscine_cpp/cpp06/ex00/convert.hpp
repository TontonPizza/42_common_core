# ifndef CONVERT_H
# define CONVERT_H

#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>


enum e_levels
{
	number = 0,
	literal = 1,
	character = 2
};

typedef struct 		s_data
{
	std::string input;
	int 		flag;
	double 		value;
}					t_data;

int 	is_valid(std::string input);
void 	display_values(t_data *data);

#endif