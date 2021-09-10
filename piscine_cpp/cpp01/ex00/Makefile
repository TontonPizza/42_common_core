NAME=ponies

all:
	clang++ -std=c++98 -Wall -Wextra -Werror *.cpp -o $(NAME)
	@valgrind ./ponies 2>err
	@grep "All" err

fclean: clean
	rm -f $(NAME)

clean:
	rm -f err