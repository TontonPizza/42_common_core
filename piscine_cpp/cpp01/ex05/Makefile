NAME=hello_brain

all:
	@clang++ -std=c++98 -Wall -Wextra -Werror *.cpp -o $(NAME)
	@valgrind ./$(NAME) > out 2>err
	@cat out
	@echo  "\n"
	@grep "All" err


fclean: clean
	rm -f $(NAME)

clean:
	rm -f out err