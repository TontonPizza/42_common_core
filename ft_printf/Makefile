# ************************************************************************** # 
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: vo-nguye <vo-nguye@42.fr>                  +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 07/10/2019 13:30:56 by vo-nguye          #+#    #+#             #
#   Updated: 07/10/2019 13:30:56 by vo-nguye         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

NAME = libftprintf.a

PARTIAL = ft_printf.a

LIBFT = libft.a

DIR_LIBFT = ./libft/

SRC	=	ft_printf.c \
		param_reader_1.c \
		param_reader_2.c \
		parse_flag.c \
		helpers_1.c \
		string_handlers.c \
		parse_d.c \
		parse_i.c \
		parse_c.c \
		parse_p.c \
		parse_zero.c \
		parse_pc.c \
		parse_s.c \
		parse_u.c \
		parse_x.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(DIR_LIBFT)
		cp $(DIR_LIBFT)$(LIBFT) ./$(NAME)
		ar rc $(NAME) $(OBJ)
		/bin/rm -f $(LIBFT)
		ranlib $(NAME)

%.o: %.c
		gcc $(FLAG) -c $< -o $@

test :
		clear
		gcc main.c libftprintf.a leoprintf.a -g3 -fsanitize=address && ./a.out

clean:
	rm -f $(OBJ)
	make clean -C $(DIR_LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C $(DIR_LIBFT)

re: fclean all

.PHONY: clean fclean all re