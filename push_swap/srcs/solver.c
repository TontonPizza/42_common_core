#include "../headers/push_swap.h"

int	coma(char *word)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (word[i])
	{
		if (word[i++] == ';')
			count++;
	}
	return (count);
}

void	undo_board(t_board board, char *mv)
{
	char		**split;
	int			size;
	char		*rmv;

	split = ft_split(mv, ';');
	size = split_size(split) - 1;
	while (size >= 0)
	{
		rmv = reverse_move(split[size]);
		execute_move(rmv, board);
		free(rmv);
		size--;
	}
	free_split(split);
}

char	*compare_chunk_size_solutions(t_board board)
{
	char	*result;
	char	*c0;
	char	*c1;

	c0 = ft_strdup(";");
	c1 = ft_strdup(";");
	solve_stacks(board, &c0, 5);
	undo_board(board, c0);
	solve_stacks(board, &c1, 9);
	undo_board(board, c1);
	if (coma(c0) < coma(c1))
		result = ft_strdup(c0);
	else
		result = ft_strdup(c1);
	free(c0);
	free(c1);
	return (result);
}

char	*best_solution(t_board board)
{
	char	*current;

	if (stack_size(board.a) < 3)
	{
		if (is_stack_ordered(board.a) == 0)
			return (ft_strdup(SA));
		else
			return (ft_strdup(""));
	}
	if (stack_size(board.a) == 3)
	{
		current = ft_strdup(";");
		solve_3(board, &current);
		return (current);
	}
	if (stack_size(board.a) <= 10)
	{
		current = ft_strdup(";");
		solve_5(board, &current);
		return (current);
	}
	else
	{
		return (compare_chunk_size_solutions(board));
	}
}

int	main(int argc, char **argv)
{
	t_board		board;
	char		*cmd;
	char		**cmds;

	if (argc == 1)
		return (0);
	(board.a) = x_malloc(sizeof(t_item *));
	(board.b) = x_malloc(sizeof(t_item *));
	(*board.a) = 0;
	(*board.b) = 0;
	array_to_stack(argc, argv, board.a);
	if (HUMAN_MODE == 1)
		display_stacks(board);
	if (is_solved(board) == 0)
	{
//		cmd = ft_strdup(";");
//		solve_ml(board, &cmd);
		cmd = best_solution(board);
		cmds = ft_split(cmd, ';');
		print_split(cmds);
		free_split(cmds);
		free(cmd);
	}
	destroy_board(&board);
	return (0);
}
