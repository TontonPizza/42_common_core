#include "../../headers/push_swap.h"

void 	sort_3(t_board board, char **cmd)
{
	t_item	*c;

	c = (*board.a);
	if (c->value > c->next->value && c->value > c->next->next->value)
	{
		*cmd = ft_strjoin_and_free(*cmd, "ra;");
		execute_move("ra", board);
	}
	else if (c->next->value > c->value && c->next->value > c->next->next->value)
	{
		*cmd = ft_strjoin_and_free(*cmd, "rra;");
		execute_move("rra", board);
	}
	c = (*board.a);
	if (c->value > c->next->value)
	{
		*cmd = ft_strjoin_and_free(*cmd, "sa;");
		execute_move("sa", board);
	}
}

void 	execute_and_append(char *move, t_board board, char **cmd)
{
	execute_move(move, board);
	*cmd = ft_strjoin_and_free(*cmd, move);
	*cmd = join_char_and_free(*cmd, ';');
}

void 	roll_a(t_board board, char **cmd)
{
	int		min;
	t_item	*c;
	int		place;

	place = 0;
	c = (*board.a);
	if (c)
		min = c->value;
	while (c)
	{
		if (c->value < min)
			min = c->value;
		c = c->next;
	}
	c = (*board.a);
	while (c && c->value != min && place++)
		c = c->next;
	if (place < stack_size(board.a) / 2)
	{
		while ((*board.a)->value != min)
			execute_and_append("ra", board, cmd);
	}
	else
		while ((*board.a)->value != min)
			execute_and_append("rra", board, cmd);
}

void 	push_a_and_sort(t_board board, char **cmd)
{
	int		size;
	int		i;
	int		k;
	t_item	*c;

	k = (*board.b)->value;
	c = (*board.a);
	size = stack_size(board.a);
	i = -1;
	while (i++ < size && c)
	{
		if (k < c->value)
			break ;
		c = c->next;
	}
	k = 0;
	if (i > size / 2)
		while (k++ < size - i)
			execute_and_append("rra", board, cmd);
	else
		while (k++ < i)
			execute_and_append("ra", board, cmd);
	execute_and_append("pa", board, cmd);
	roll_a(board, cmd); // pas necessaire
}

void 	solve_recursive(t_board board, char **cmd)
{
	if (stack_size(board.a) <= 3)
		sort_3(board, cmd);
	if (stack_size(board.a) == 5 && stack_size(board.b) == 0)
	{
		solve_5(board, cmd);
	}
	if (is_stack_ordered(board.a) == 1 && is_solved(board) == 0)
	{
		push_a_and_sort(board, cmd);
	}
	else if (stack_size(board.a) > 3)
	{
		execute_and_append("pb", board, cmd);
	}
	if (is_solved(board) == 1)
		return ;
	else
		solve_recursive(board, cmd);
}
