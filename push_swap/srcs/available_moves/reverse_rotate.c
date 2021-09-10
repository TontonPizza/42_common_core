#include "../../headers/push_swap.h"

void 	reverse_rotate_stack(t_item **stack)
{
	t_item	*current;
	int		i;

	current = (*stack);
	while (current && current->next && current->next->next)
	{
		current = current->next;
	}
	if (current && current->next)
	{
		i = current->next->value;
		free(current->next);
		current->next = 0;
		push(stack, i);
	}
}

void 	reverse_a(t_board board)
{
	reverse_rotate_stack(board.a);
}

void	reverse_b(t_board board)
{
	reverse_rotate_stack(board.b);
}

void 	reverse_ab(t_board board)
{
	reverse_a(board);
	reverse_b(board);
}
