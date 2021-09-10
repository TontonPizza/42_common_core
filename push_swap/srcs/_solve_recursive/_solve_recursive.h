#ifndef _SOLVE_RECURSIVE_H
# define _SOLVE_RECURSIVE_H

# include "../../headers/push_swap.h"

void	solve_recursive(t_board board, char **cmd);
void	push_b_opti(t_board board, char **cmd);
void	execute_and_append(char *mv, t_board board, char **cmd);
int		is_almost_ordered(t_item **stack);
void	roll_a(t_board board, char **cmd);
void	push_smaller_of_three(t_board board, char **cmd);

#endif //PUSH_SWAP__SOLVE_H
