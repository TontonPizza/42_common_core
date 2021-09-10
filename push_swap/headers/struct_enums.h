#ifndef STRUCT_ENUMS_H
# define STRUCT_ENUMS_H

# ifndef HUMAN_MODE
#  define HUMAN_MODE 0
# endif

# ifndef MAX_INT
#  define MAX_INT "2147483648"
# endif

# ifndef MAX_SIZE
#  define MAX_SIZE 10000000
# endif

# ifndef MAX_MOVES
#  define MAX_MOVES 100
# endif

# ifndef PA
#  define PA "pa"
# endif

# ifndef PB
#  define PB "pb"
# endif

# ifndef SA
#  define SA "sa"
# endif

# ifndef SB
#  define SB "sb"
# endif

# ifndef SS
#  define SS "ss"
# endif

# ifndef PA
#  define PA "pa"
# endif

# ifndef RA
#  define RA "ra"
# endif

# ifndef RB
#  define RB "rb"
# endif

# ifndef RRA
#  define RRA "rra"
# endif

# ifndef RRB
#  define RRB "rrb"
# endif

# ifndef RR
#  define RR "rr"
# endif

# ifndef RRR
#  define RRR "rrr"
# endif

typedef struct s_item
{
	int				value;
	struct s_item	*next;
	float			score;
}				t_item;

typedef struct s_board
{
	t_item	**a;
	t_item	**b;
}				t_board;

enum e_operation_type
{
	get,
	set,
	destroy
};

enum e_operation_lag
{
	fail,
	success
};

typedef struct s_node
{
	char	*mv; // moves
	int		move_count;
	int		evaluation;
	char	available;
}				t_node;

#endif //PUSH_SWAP_STRUCT_ENUMS_H
