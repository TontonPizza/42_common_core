#include "span.hpp"


span::span(): size(0)
{
}

span::span(unsigned int n): size(n)
{
	this->array.reserve(n);
}

void 	span::addNumber(const int value)
{
	if (this->array.size() < size)
		this->array.push_back(value);
	else
		throw(std::runtime_error("array is full"));
	return ;
}

long int 	span::shortestSpan() const
{
	if (this->array.size() < 2)
		throw (std::runtime_error("not enought elements"));
	std::vector<int> v = this->array;
	std::sort(v.begin(), v.end());
	std::adjacent_difference(v.begin(), v.end(), v.begin());
	return *std::min_element(v.begin(), v.end());
}

long int	span::longestSpan() const
{
	if (this->array.size() < 2)
		throw (std::runtime_error("not enought elements"));
	int min = *std::min_element(this->array.begin(), this->array.end());
	int max = *std::max_element(this->array.begin(), this->array.end());
	return (max - min);
}

static void display_int(int n){ std::cout << n << " "; }

void 	span::display_array()
{
	std::for_each(this->array.begin(), this->array.end(), &display_int);
	std::cout << std::endl;
}

span::span(const span & T): size(T.size)
{
	this->array = T.array;
}

span::~span()
{
}

span & span::operator=(const span & T)
{
	this->array = T.array;
	this->size = T.size;
	return (*this);
}