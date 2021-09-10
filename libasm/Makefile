

.DEFAULT_GOAL := libasm.a

NAME = libasm.a

NASM = nasm -f elf64

FLAG = -lc -include /usr/include/errno.h -no-pie -fsanitize=address

####### Objects			#######

SRCS = srcs/

OBJS =	ft_strlen.o \
		ft_strcpy.o \
		ft_write.o  \
		ft_strcmp.o \
		ft_strdup.o \
		ft_read.o	\

ft_read.o : $(SRCS)ft_read.s
			$(NASM) $< -o $@

ft_strdup.o : $(SRCS)ft_strdup.s
			$(NASM) $< -o $@

ft_strlen.o : $(SRCS)ft_strlen.s
			$(NASM) $< -o $@

ft_strcpy.o : $(SRCS)ft_strcpy.s
			$(NASM) $< -o $@

ft_write.o : $(SRCS)ft_write.s
			$(NASM) $< -o $@

ft_strcmp.o : $(SRCS)ft_strcmp.s
			$(NASM) $< -o $@

####### Mandatory rules #######

exec : all
		gcc  $(FLAG) main.c $(NAME)
		make clean
		./a.out

all : $(NAME)

$(NAME) : $(OBJS)
		ar -rc $(NAME) $(OBJS)
		ranlib $(NAME)

fclean : clean
		rm -rf $(NAME) a.out

clean :
		rm -rf $(OBJS)

re :	fclean all

.PHONY : clean fclean re all
