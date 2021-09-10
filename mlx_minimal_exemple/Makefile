NAME = wrapped_mlx

DIR_MLX = ./minilibx/

COMPILE = gcc
CFLAGS = -Wall -Wextra -Werror

MINI_OBS =  ./minilibx/*.o


OBJ = $(SRC:.c=.o)

%.o: %.c
	$(COMPILE) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
		rm -rf $(NAME)
		make -C $(DIR_MLX)
		$(COMPILE) $(CFLAGS) main.c $(MINI_OBS) -I$(INCL) -lm  -lXext -lX11 -lbsd -o $(NAME)

clean:
	rm -rf $(MINI_OBS)
	rm -rf main.o

fclean: clean
	rm wrapped_mlx