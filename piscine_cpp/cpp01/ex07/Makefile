NAME=best_sed
all:
	@clang++ -std=c++98 -Wall -Wextra -Werror *.cpp -o $(NAME)
	@./$(NAME) test_files/leconte_de_lisle_les_elfes Elfes Pokémons > out 2>err
	@valgrind ./$(NAME) test_files/justin_bieber_yummy yummy pika > out 2>err
	@cat out
	@echo  "\n"
	@grep "All" err
	@rm -f err out


fclean: clean
	rm -f $(NAME)

clean:
	rm -f out err
	rm -f test_files/*.replace