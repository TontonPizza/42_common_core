#include "libft.h"

int 	max_of_two(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int 	min_of_two(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int 	abs_val(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
