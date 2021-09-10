#include "../headers/push_swap.h"

void	set_g_l(void)
{
	char		*line;
	char		**split;

	get_next_line(0, &line);
	split = ft_split(line, ' ');
	g_l1 = ft_atoi(split[0]);
	g_l2 = ft_atoi(split[1]);
	g_l3 = ft_atoi(split[2]);
	free_split(split);
	free(line);
}

int	main(int argc, char **argv)
{
	t_board		board;
	char		*cmd;
	char		**cmds;

	set_g_l();
	if (argc == 1)
		return (0);
	(board.a) = x_malloc(sizeof(t_item *));
	(board.b) = x_malloc(sizeof(t_item *));
	(*board.a) = 0;
	(*board.b) = 0;
	array_to_stack(argc, argv, board.a);
	if (is_solved(board) == 0)
	{
		cmd = ft_strdup(";");
		solve_ml(board, &cmd);
		cmds = ft_split(cmd, ';');
		print_split(cmds);
		free_split(cmds);
		free(cmd);
	}
	destroy_board(&board);
	return (0);
}
