#include "../headers/push_swap.h"

void	routine(t_board board)
{
	char	*line;

	line = 0;
	if (HUMAN_MODE == 1)
		display_stacks(board);
	while (get_next_line(0, &line))
	{
		execute_move(line, board);
		free(line);
		line = 0;
		if (HUMAN_MODE == 1)
			display_stacks(board);
	}
}

int	main(int argc, char **argv)
{
	t_board		board;

	if (argc == 1)
		return (0);
	(board.a) = x_malloc(sizeof(t_item *));
	(board.b) = x_malloc(sizeof(t_item *));
	(*board.a) = 0;
	(*board.b) = 0;
	array_to_stack(argc, argv, board.a);
	routine(board);
	if (is_solved(board))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	destroy_board(&board);
	return (0);
}
