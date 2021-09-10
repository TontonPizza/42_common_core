#include <string>
#include <iostream>
#include <cstdlib>
#include <list>
#include "MutantStack.hpp"


void test_copy()
{
	std::cout << "TEST copy" << std::endl;
	MutantStack<int> original;
	original.push(9);

	MutantStack<int> copy(original);
	std::cout << "copy expected to contain 9 : " << static_cast<int>(copy.top()) << std::endl;
	copy.pop();
	std::cout << "original size expected to be 1 : " << original.size() << std::endl;
	std::cout << "copy size expected to be 0 : " << copy.size() << std::endl;
	std::cin.get();
}


void test_reverse()
{
	std::cout << "TEST reverse" << std::endl;
	MutantStack<int> stk;

	stk.push(1);
	stk.push(2);
	stk.push(3);

	MutantStack<int>::reverse_iterator rit = stk.rbegin();
	MutantStack<int>::reverse_iterator rite = stk.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		++rit;
	}

	std::cout << "- - - " << std::endl;
	MutantStack<int>::iterator it = stk.begin();
	MutantStack<int>::iterator ite = stk.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cin.get();
}

void test_subject()
{
	std::cout << "TEST subject" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top()  << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();


	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cin.get();
}

void 	test_list()
{
	std::cout << "TEST list" << std::endl;
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back()  << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();


	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	std::cin.get();
}


int main()
{


	test_subject();
	test_list();
	test_copy();
	test_reverse();
}