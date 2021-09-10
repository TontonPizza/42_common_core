#include "../../headers/push_swap.h"

int 	swap(t_item **stack)
{
	int		tmp;

	if ((*stack) == 0 || (*stack)->next == 0)
	{
		return (-1);
	}
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	operation_flag(set, success);
	return (0);
}

void 	swap_a(t_board board)
{
	swap(board.a);
}

void	swap_b(t_board board)
{
	swap(board.b);
}

void 	swap_ab(t_board board)
{
	swap_a(board);
	swap_b(board);
}
