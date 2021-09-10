#include "../../headers/push_swap.h"

int 	pop(t_item **stack)
{
	t_item	*tmp;
	int		result;

	if (*stack == NULL)
	{
		operation_flag(set, fail);
		return (-1);
	}
	tmp = *stack;
	result = tmp->value;
	(*stack) = (*stack)->next;
	free(tmp);
	operation_flag(set, success);
	return (result);
}
