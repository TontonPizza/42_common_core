#include "../../headers/push_swap.h"

void	free_stack(t_item *current)
{
	if (current && current->next)
	{
		free_stack(current->next);
	}
	if (current != 0)
		free(current);
}

void	destroy_board(t_board *board)
{
	t_item	*current;

	current = *board->a;
	free_stack(current);
	current = *board->b;
	free_stack(current);
	free(board->a);
	free(board->b);
}
