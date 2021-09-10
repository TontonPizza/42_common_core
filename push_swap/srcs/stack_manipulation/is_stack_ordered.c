#include "../../headers/push_swap.h"

int 	last_stack_value(t_item **stack)
{
	int		i;
	t_item	*current;

	current = (*stack);
	i = -1;
	while (current)
	{
		i = current->value;
		current = current->next;
	}
	return (i);
}

int 	is_stack_asc(t_item **stack)
{
	t_item	*current;

	current = (*stack);
	while (current && current->next)
	{
		if (current->value != current->next->value - 1)
			return (0);
		current = current->next;
	}
	return (1);
}

int 	is_stack_desc(t_item **stack)
{
	t_item	*current;

	current = (*stack);
	while (current && current->next)
	{
		if (current->value != 1 + current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int 	is_stack_ordered(t_item **stack)
{
	t_item	*current;

	current = (*stack);
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
