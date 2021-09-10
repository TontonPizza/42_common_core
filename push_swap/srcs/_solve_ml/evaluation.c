#include "../../headers/push_swap.h"

// --A-B-C-D--
// --0-1-2-3-- size 4;
// --0-1-2-1-- nb of moves to get it to top

float 	score(int val, int index)
{
	float	result;

	result = g_l1 * val - g_l2 * index + g_l3 * val * index;
	return (result);
}

void 	evaluate_positions(t_board board)
{
	int		rank;
	int		fixed_rank;
	int		size;
	t_item	*current;

	rank = 0;
	size = stack_size(board.a) + stack_size(board.b);
	current = (*board.a);
	while (current)
	{
		fixed_rank = min_of_two(rank, size - rank);
		current->score = score(current->value, fixed_rank);
		current = current->next;
		rank++;
	}
}
