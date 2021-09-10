#include "../../headers/push_swap.h"

int 	is_almost_ordered(t_item **stack)
{
	t_item	*current;
	int		max;

	max = -1;
	current = (*stack);
	while (current && current->next)
	{
		if (current->value > current->next->value)
		{
			max = current->value;
			current = current->next;
			break ;
		}
		current = current->next;
	}
	while (current && current->next && max >= 0)
	{
		if (current->value > current->next->value)
			return (0 + is_stack_ordered(stack));
		current = current->next;
	}
	if (current && current->value > max)
		return (0 + is_stack_ordered(stack));
	return (1);
}

void 	push_smaller_of_three(t_board board, char **cmd)
{
	int		last;
	int		first;
	int		second;

	second = (*board.a)->next->value;
	first = (*board.a)->value;
	last = last_stack_value(board.a);
	if (second < first && second < last)
		execute_and_append("ra", board, cmd);
	else if (last < second && last < first)
		execute_and_append("rra", board, cmd);
	execute_and_append("pb", board, cmd);
}

void 	push_b_opti(t_board board, char **cmd)
{
	int		size;
	int		i;
	int		k;
	t_item	*c;

	k = (*board.b)->value;
	c = (*board.a);
	size = stack_size(board.a);
	i = 0;
	while (i < size && c != 0 && k < c->value && i++)
		c = c->next;
	while (i < size && c != 0 && k > c->value && i++)
		c = c->next;
	k = 0;
	if (i > size / 2)
		while (k++ < size - i)
			execute_and_append("rra", board, cmd);
	else
		while (k++ < i)
			execute_and_append("ra", board, cmd);
	execute_and_append("pa", board, cmd);
}
