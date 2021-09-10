
HPP=	templates/base_structures.hpp \
		templates/comparison.hpp \
		templates/enable_if.hpp \
		templates/iterator.hpp \
		templates/map.hpp \
		templates/pair.hpp \
		templates/vector.hpp\
		templates/stack.hpp\

all:
	clang++ -Wall -Wextra -Werror -std=c++98 main_vector.cpp colors/*.cpp -o exv_test_vector
	clang++ -Wall -Wextra -Werror -std=c++98 main_stack.cpp colors/*.cpp -o exs_test_stack
	clang++ -Wall -Wextra -Werror -std=c++98 main_map.cpp colors/*.cpp -o exm_test_map

clean:
	rm exv_test_vector exs_test_stack exm_test_map