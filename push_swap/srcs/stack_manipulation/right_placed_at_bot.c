#include "../../headers/push_swap.h"

int	right_placed_at_bot_a(t_board board)
{
	int		i;
	int		size;
	int		count;
	t_item	*current;

	count = 0;
	i = stack_size(board.b);
	size = stack_size(board.a) + i;
	current = (*board.a);
	while (i < size && current)
	{
		if (current->value == i)
			count++;
		else
			count = 0;
		i++;
		current = current->next;
	}
	return (count);
}

int	right_placed_at_top_b(t_board board)
{
	int		i;
	int		count;
	t_item	*current;

	count = 0;
	i = stack_size(board.b) - 1;
	current = (*board.b);
	while (i >= 0 && current)
	{
		if (current->value == i)
			count++;
		else
			break ;
		i--;
		current = current->next;
	}
	return (count);
}
