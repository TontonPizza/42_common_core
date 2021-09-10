#include "../../headers/push_swap.h"

void	execute_move(char *line, t_board board)
{
	if (vo_strcmp(line, "pa") == 0)
		push_ba(board);
	else if (vo_strcmp(line, "pb") == 0)
		push_ab(board);
	else if (vo_strcmp(line, "sa") == 0)
		swap_a(board);
	else if (vo_strcmp(line, "sb") == 0)
		swap_b(board);
	else if (vo_strcmp(line, "ss") == 0)
		swap_ab(board);
	else if (vo_strcmp(line, "ra") == 0)
		rotate_a(board);
	else if (vo_strcmp(line, "rb") == 0)
		rotate_b(board);
	else if (vo_strcmp(line, "rrb") == 0)
		reverse_b(board);
	else if (vo_strcmp(line, "rra") == 0)
		reverse_a(board);
	else if (vo_strcmp(line, "rr") == 0)
		rotate_ab(board);
	else if (vo_strcmp(line, "rrr") == 0)
		reverse_ab(board);
	else
		ft_putstr_fd("no valid move\n", STDERR_FILENO);
}
