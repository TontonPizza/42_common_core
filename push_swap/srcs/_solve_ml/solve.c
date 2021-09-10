#include "../../headers/push_swap.h"

void 	push_biggest_to_a(t_board board, char **cmd)
{
	int		rank;
	int		max;
	t_item	*current;

	rank = 0;
	max = max_in_stack(board.b);
	current = (*board.b);
	while (current)
	{
		if (current->value == max)
			break ;
		current = current->next;
		rank++;
	}
	if (rank > stack_size(board.b) / 2)
		rotate_and_push_to_a(board, cmd, RRB, stack_size(board.b) - rank);
	else
		rotate_and_push_to_a(board, cmd, RB, rank);
}

void 	a_to_b(t_board board, char **cmd)
{
	while (stack_size(board.a) > 0)
	{
		evaluate_positions(board);
		push_best_score(board, cmd);
	}
}

void 	b_to_a(t_board board, char **cmd)
{
	while (stack_size(board.b) > 0)
	{
		push_biggest_to_a(board, cmd);
		if (stack_size(board.a) == 2 && is_stack_asc(board.a) == 0)
			execute_and_append("sa", board, cmd);
	}
}

void	solve_ml(t_board board, char **cmd)
{
	if (is_solved(board))
		return ;
	a_to_b(board, cmd);
	b_to_a(board, cmd);
}
