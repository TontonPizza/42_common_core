NAME		=	philo_three
HEADERS		=	headers
FLAGS		=	-Wall -Wextra -Werror
LEAKS		=	-fsanitize=address
DIR_OBJS	=	objs/
CC			=	gcc

SRCS		=	main_philo_three.c \
				\
				time/time.c\
				time/wait_and_check.c\
				\
				philo_three_routine/actions.c\
				philo_three_routine/display_message.c\
				philo_three_routine/philosophers.c\
				\
				input/get_input.c\
				\
				error_management/error_management.c\



OBJ		=	$(SRCS:.c=.o)

%.o : %.c
	gcc $(FLAGS)  -I $(HEADERS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf *.o
	rm -rf */*.o

fclean : clean
	rm -rf $(NAME)

re : fclean all

leaks :	$(OBJ)
	$(CC) $(FLAGS) $(LEAKS) $(OBJ) -o $(NAME)

linux:	$(OBJ)
	$(CC) $(FLAGS) $(SRCS) -lpthread -o $(NAME)


