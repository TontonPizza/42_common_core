#include "../../headers/push_swap.h"

void 	rotate_stack(t_item **stack)
{
	t_item	*current;
	int		i;

	i = 0;
	current = (*stack);
	while (current && current->next)
	{
		current = current->next;
		i++;
	}
	if (current && i >= 1)
	{
		free(current->next);
		current->next = create_item(pop(stack));
	}
}

void 	rotate_a(t_board board)
{
	rotate_stack(board.a);
}

void 	rotate_b(t_board board)
{
	rotate_stack(board.b);
}

void 	rotate_ab(t_board board)
{
	rotate_a(board);
	rotate_b(board);
}
