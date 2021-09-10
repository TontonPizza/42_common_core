#include "../../headers/push_swap.h"

void	push_ab(t_board board)
{
	int		i;

	i = pop(board.a);
	if (operation_flag(get, 0) == success)
		push(board.b, i);
}

void	push_ba(t_board board)
{
	int		i;

	i = pop(board.b);
	if (operation_flag(get, 0) == success)
		push(board.a, i);
}
