#include "../../headers/push_swap.h"

char 	operation_flag(int op, char value)
{
	static char	flag;

	if (op == set)
		flag = value;
	return (flag);
}
