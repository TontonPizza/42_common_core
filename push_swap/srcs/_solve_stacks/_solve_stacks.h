#ifndef _SOLVE_STACKS_H
# define _SOLVE_STACKS_H

# include "../../headers/push_swap.h"

typedef struct s_chunk
{
	int		size;
	int		count;
	int		pushed;
}				t_chunk;

void	solve_stacks(t_board board, char **cmd, int chunk_size);
int		med_val(t_item **stack, t_chunk chunk);
void	rotate_and_push_to_a(t_board board, char **cmd, char *mv, int count);
void	rotate_and_push_to_b(t_board board, char **cmd, char *mv, int count);

#endif //PUSH_SWAP__SOLVE_H
