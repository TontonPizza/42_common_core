#include "span.hpp"
#include <vector>
#include <ctime>

int small_random()
{
	return (std::rand() % 10000);
}

void test_10k_values()
{
	std::cout << "TEST span 10k values" << std::endl;

	std::srand(unsigned(std::time(NULL)));
	std::vector<int> v(10000);
	std::generate(v.begin(), v.end(), small_random);

	span sp = span(10000);
	sp.addNumber(v.begin(), v.end());
	sp.display_array();
	std::cout << "short span = " << sp.shortestSpan() << std::endl;
	std::cout << "long span = " << sp.longestSpan() << std::endl;
	std::cin.get();

}


void test_add_range()
{
	std::cout << "TEST span add range" << std::endl;
	span sp = span(500);

	std::vector<int> v(5, 6);
	sp.addNumber(v.begin(), v.end());
	sp.display_array();
	std::cin.get();

}

void test_add_too_much()
{
	std::cout << "TEST span size 1" << std::endl;
	span sp = span(0);

	try
	{
		sp.addNumber(5);
	}
	catch(std::exception & e) { std::cout << e.what() << std::endl; }
	std::cin.get();

}

void test_empty_span()
{
	std::cout << "TEST span size 0" << std::endl;
	span sp = span(0);

	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception & e) { std::cout << e.what() << std::endl; }
	std::cin.get();
}

void test_small_span()
{
	std::cout << "TEST span size 1" << std::endl;
	span sp = span(1);

	sp.addNumber(5);
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception & e) { std::cout << e.what() << std::endl; }
	std::cin.get();
}

void test_subject()
{
	std::cout << "TEST subject" << std::endl;
	span sp = span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cin.get();
}

int main()
{
	test_subject();
	test_small_span();
	test_add_too_much();
	test_empty_span();
	test_add_range();
	test_10k_values();
}