#include "../../headers/push_swap.h"

void	push_val(t_board board, char **cmd, int val)
{
	int		index;
	int		count;
	t_item	*current;

	index = 0;
	count = 0;
	current = (*board.a);
	while (current && current->value != val)
	{
		index++;
		current = current->next;
	}
	if (index > stack_size(board.a) - index)
	{
		while (count++ < stack_size(board.a) - index)
			execute_and_append(RRA, board, cmd);
	}
	else
	{
		while (count++ < index)
			execute_and_append(RA, board, cmd);
	}
	execute_and_append(PB, board, cmd);
}

void	solve_3(t_board board, char **cmd)
{
	t_item	*c;

	c = (*board.a);
	if (c->value > c->next->value && c->value > c->next->next->value)
		execute_and_append(RA, board, cmd);
	c = (*board.a);
	if (c->next->value > c->value && c->next->value > c->next->next->value)
		execute_and_append(RRA, board, cmd);
	c = (*board.a);
	if (c->value > c->next->value)
		execute_and_append(SA, board, cmd);
}

void	solve_5(t_board board, char **cmd)
{
	int		i;

	i = 0;
	if (is_solved(board) == 1)
		return ;
	while (stack_size(board.a) > 3)
		push_val(board, cmd, i++);
	solve_3(board, cmd);
	while (stack_size(board.b) > 0)
		execute_and_append (PA, board, cmd);
}
