NAME=plumber

all:
	@clang++ -std=c++98 -Wall -Wextra -Werror *.cpp -o $(NAME)
	@valgrind ./$(NAME) > out 2>err
	@cat out
	@grep "All" err

fclean: clean
	rm -f $(NAME)

clean:
	rm -f err out