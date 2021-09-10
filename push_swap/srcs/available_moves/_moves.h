#ifndef _MOVES_H
# define _MOVES_H

# include "../../headers/push_swap.h"

# ifndef EMPTY_CMD
#  define EMPTY_CMD "xx"
# endif

void		execute_move(char *line, t_board board);
void		swap_ab(t_board board);
void		swap_a(t_board board);
void		swap_b(t_board board);
void		push_ba(t_board board);
void		push_ab(t_board board);
void		rotate_a(t_board board);
void		rotate_b(t_board board);
void		rotate_ab(t_board board);
void		reverse_a(t_board board);
void		reverse_b(t_board board);
void		reverse_ab(t_board board);
char		*reverse_move(char *move);

#endif //PUSH_SWAP__MOVES_H
