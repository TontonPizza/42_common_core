#ifndef _INITIALIZATION_H
# define _INITIALIZATION_H

# include "../../headers/push_swap.h"

void		bubble_sort(int size, int *array);
void		array_to_stack(int argc, char **argv, t_item **stack_a);
int			check_input(char *input, const char *max_int);
t_item		*init_stack_b(int size);
int			*normalize(int argc, char **argv);
t_board		*copy_board(t_board source);
int			stack_size(t_item **stack);

#endif //PUSH_SWAP__INITIALIZATION_H
