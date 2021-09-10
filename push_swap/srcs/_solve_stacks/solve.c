#include "../../headers/push_swap.h"

static void 	push_easy_small(t_board board, char **cmd, int med)
{
	int		first;
	int		last;
	t_item	*current;
	int		i;

	first = 0;
	i = 0;
	last = stack_size(board.a);
	current = (*board.a);
	while (current && current->value > med && ++first)
		current = current->next;
	current = (*board.a);
	while (current)
	{
		if (current->value < med)
			last = i;
		current = current->next;
		i++;
	}
	last = stack_size(board.a) - last;
	if (first < last)
		rotate_and_push_to_b(board, cmd, RA, first);
	else
		rotate_and_push_to_b(board, cmd, RRA, last);
}

static void 	push_biggest_to_a(t_board board, char **cmd)
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

static void 	a_to_b(t_board board, char **cmd, t_chunk c)
{
	int		med;
	int		pushed;

	pushed = 0;
	while (stack_size(board.a) > 0)
	{
		if (pushed >= c.size / 2)
		{
			pushed = 0;
			c.count++;
			med = med_val(board.a, c);
		}
		push_easy_small(board, cmd, med);
		pushed++;
	}
}

static void 	b_to_a(t_board board, char **cmd)
{
	while (stack_size(board.b) > 0)
	{
		push_biggest_to_a(board, cmd);
		if (stack_size(board.a) == 2 && is_stack_asc(board.a) == 0)
			execute_and_append("sa", board, cmd);
	}
}

void	solve_stacks(t_board board, char **cmd, int chuck_size)
{
	t_chunk	chunk;

	chunk.size = stack_size(board.a) / chuck_size;
	chunk.count = 0;
	if (is_solved(board))
		return ;
	a_to_b(board, cmd, chunk);
	b_to_a(board, cmd);
}
