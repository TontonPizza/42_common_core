#include "../../headers/push_swap.h"

void	breakpoint(char *msg)
{
	char	*line;

	if (msg)
	{
		ft_putstr_fd(msg, STDERR_FILENO);
	}
	ft_putendl_fd(" >>>", STDERR_FILENO);
	line = 0;
	get_next_line(0, &line);
	free(line);
}
