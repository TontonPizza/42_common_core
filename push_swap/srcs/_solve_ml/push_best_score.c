#include "../../headers/push_swap.h"

int 	best_score_index(t_board board)
{
	int		i;
	int		rank;
	int		max;
	t_item	*current;

	i = 0;
	rank = 0;
	current = (*board.a);
	max = current->score;
	while (current)
	{
		if (current->score > max)
		{
			max = current->score;
			rank = i;
		}
		current = current->next;
		i++;
	}
	return (rank);
}

void 	push_best_score(t_board board, char **cmd)
{
	int		size;
	int		rank;
	int		fixed_rank;

	size = stack_size(board.a);
	rank = best_score_index(board);
	fixed_rank = size - rank;
	size = 0;
	if (fixed_rank < rank)
	{
		while (size++ < fixed_rank)
			execute_and_append(RRA, board, cmd);
	}
	else
	{
		while (size++ < rank)
			execute_and_append(RA, board, cmd);
	}
	execute_and_append(PB, board, cmd);
}
