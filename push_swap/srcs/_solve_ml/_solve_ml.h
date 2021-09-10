#ifndef _SOLVE_ML_H
# define _SOLVE_ML_H

# include "../../headers/push_swap.h"

int		g_l1;
int		g_l3;
int		g_l2;
int		g_l4;

void	solve_ml(t_board board, char **cmd);
void	evaluate_positions(t_board board);
void	push_best_score(t_board board, char **cmd);

#endif //PUSH_SWAP__SOLVE_ML_H
