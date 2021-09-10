#include "../../headers/push_swap.h"

int	min_in_stack(t_item **stack)
{
	int		min;
	t_item	*current;

	min = MAX_SIZE;
	current = (*stack);
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	max_in_stack(t_item **stack)
{
	int		max;
	t_item	*current;

	max = -1;
	current = (*stack);
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	stack_size(t_item **stack)
{
	t_item	*current;
	int		i;

	i = 0;
	current = (*stack);
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
