#include "../../headers/push_swap.h"

int 	med_val(t_item **stack, t_chunk c)
{
	int		range;
	int		*values;
	int		i;
	t_item	*current;

	current = (*stack);
	range = stack_size(stack);
	values = x_malloc(sizeof(int) * range);
	i = 0;
	while (i < range)
	{
		values[i++] = current->value;
		current = current->next;
	}
	bubble_sort(range, values);
	if (range > c.size)
		i = values[c.size / 2];
	else
		i = values[range / 2];
	free(values);
	return (i);
}

int 	biggest_of_two_is_top(t_item **stack)
{
	int		top;
	int		bot;
	t_item	*current;

	current = (*stack);
	top = current->value;
	while (current)
	{
		bot = current->value;
		current = current->next;
	}
	if (top > bot)
		return (1);
	return (0);
}

int 	smallest_of_two_is_top(t_item **stack)
{
	int		top;
	int		bot;
	t_item	*current;

	current = (*stack);
	top = current->value;
	while (current)
	{
		bot = current->value;
		current = current->next;
	}
	if (top < bot)
		return (1);
	return (0);
}

void 	rotate_and_push_to_b(t_board board, char **cmd, char *mv, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		execute_and_append(mv, board, cmd);
		i++;
	}
	if (HUMAN_MODE == 1)
	{
		breakpoint("before push b");
		display_stacks(board);
	}
	execute_and_append(PB, board, cmd);
	if (HUMAN_MODE == 1)
	{
		breakpoint("execute push b");
		display_stacks(board);
	}
}

void 	rotate_and_push_to_a(t_board board, char **cmd, char *mv, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		execute_and_append(mv, board, cmd);
		i++;
	}
	if (HUMAN_MODE == 1)
	{
		breakpoint("before push a");
		display_stacks(board);
	}
	execute_and_append(PA, board, cmd);
	if (HUMAN_MODE == 1)
	{
		breakpoint("execute push a");
		display_stacks(board);
	}
}
