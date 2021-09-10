#ifndef CPP08_SPAN_HPP
#define CPP08_SPAN_HPP

#include <numeric>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>

class span {
public:
						span(unsigned int n);
						span(const span & T);
						~span();
						span &operator=(const span & T);
		void			addNumber(const int value);
		long int		shortestSpan() const;
		long int 		longestSpan() const;
		void 			display_array();

		template<typename T>
		void 			addNumber(T begin, T end)
		{
			if (static_cast<unsigned long>(std::distance(begin, end)) > (size - this->array.size()))
				throw(std::runtime_error("array is full"));
			this->array.insert(this->array.begin(), begin, end);
		}

private:
						span();
	unsigned int		size;
	std::vector<int>	array;
};


#endif //CPP08_SPAN_HPP
