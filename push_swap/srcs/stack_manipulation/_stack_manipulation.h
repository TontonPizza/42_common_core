#ifndef _STACK_MANIPULATION_H
# define _STACK_MANIPULATION_H

# include "../../headers/push_swap.h"

int		right_placed_at_top_b(t_board board);
int		last_stack_value(t_item **stack);
int		is_stack_asc(t_item **stack);
int		is_stack_desc(t_item **stack);
int		get_size(int op, int val);
int		is_stack_ordered(t_item **stack);
void	push(t_item **stack, int value);
int		pop(t_item **stack);
int		swap(t_item **stack);
t_item	*create_item(int value);
char	operation_flag(int op, char value);
int		min_in_stack(t_item **stack);
int		max_in_stack(t_item **stack);
int		right_placed_at_bot_a(t_board board);

#endif //PUSH_SWAP__STACK_MANIPULATION_H
