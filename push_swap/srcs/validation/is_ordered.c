#include "../../headers/push_swap.h"

int 	is_solved(t_board board)
{
	int		i;
	t_item	*current;

	if ((*board.b) != 0)
		return (0);
	i = (*board.a)->value;
	current = (*board.a)->next;
	while (current)
	{
		if (current->value < i)
			return (0);
		i = current->value;
		current = current->next;
	}
	return (1);
}
