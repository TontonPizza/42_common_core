#include "../../headers/push_swap.h"

void 	display_stacks(t_board board)
{
	t_item	*current;

	current = *(board.a);
	ft_putstr_fd("A: ", STDERR_FILENO);
	while (current)
	{
		ft_putnbr_fd(current->value, STDERR_FILENO);
		ft_putchar_fd(' ', STDERR_FILENO);
		current = current->next;
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	current = *(board.b);
	ft_putstr_fd("B: ", STDERR_FILENO);
	while (current)
	{
		ft_putnbr_fd(current->value, STDERR_FILENO);
		ft_putchar_fd(' ', STDERR_FILENO);
		current = current->next;
	}
	ft_putchar_fd('\n', STDERR_FILENO);
}
