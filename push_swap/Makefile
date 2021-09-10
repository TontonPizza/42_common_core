NAME=push_swap

SRCS=	\
		srcs/error_management/error_management.c\
		\
		srcs/tools/display_stack.c\
		srcs/tools/destroy_board.c\
		srcs/tools/breakpoint.c\
		\
		srcs/initializations/init_stack.c\
		srcs/initializations/init_board.c\
		srcs/initializations/normalize.c\
		\
		srcs/validation/is_ordered.c\
		\
		srcs/available_moves/swap.c\
		srcs/available_moves/push_pop.c\
		srcs/available_moves/rotate.c\
		srcs/available_moves/reverse_rotate.c\
		srcs/available_moves/execute_moves.c\
		srcs/available_moves/reverse_move.c\
		\
		srcs/stack_manipulation/push.c\
		srcs/stack_manipulation/pop.c\
		srcs/stack_manipulation/stack_size.c\
		srcs/stack_manipulation/is_stack_ordered.c\
		srcs/stack_manipulation/create_item.c\
		srcs/stack_manipulation/operation_flag.c\
		srcs/stack_manipulation/right_placed_at_bot.c\
		\
		srcs/_solve_recursive/solve.c\
		srcs/_solve_recursive/push_b_opti.c\
		\
		srcs/_solve_stacks/solve.c\
		srcs/_solve_stacks/helpers.c\
		\
		srcs/_solve_ml/solve.c\
		srcs/_solve_ml/push_best_score.c\
		srcs/_solve_ml/evaluation.c\
		\
		srcs/_solve_5/solve_5.c\


all : $(NAME)

libft/libft.a :
	make -C libft

$(NAME) : $(SRCS) srcs/checker.c srcs/solver.c libft/libft.a
	gcc $(SRCS) -fsanitize=address -Wall -Wextra -Werror srcs/checker.c libft/libft.a -o checker
	gcc $(SRCS) -fsanitize=address -Wall -Wextra -Werror srcs/solver.c libft/libft.a -o push_swap

clean :
	rm -f checker push_swap trace.txt checker push_eval miner libft/libft.a
	make fclean -C libft

fclean : clean

re : fclean all

check : d_check p_check

d_check : $(SRCS)
	gcc $(SRCS) -D HUMAN_MODE=1 -fsanitize=address srcs/checker.c libft/libft.a -o checker

p_check : $($SRCS)
	gcc $(SRCS) -D HUMAN_MODE=1 -fsanitize=address srcs/solver.c libft/libft.a -o push_swap

eval	: $(SRCS)
	gcc $(SRCS) -fsanitize=address -Wall -Wextra -Werror srcs/eval.c libft/libft.a -o push_eval

analyse	: $($SRCS)
	gcc $(SRCS) -fsanitize=address -Wall -Wextra -Werror analyser/analyse_results.c libft/libft.a -o miner
