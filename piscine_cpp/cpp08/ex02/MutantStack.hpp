#ifndef CPP08_MUTANTSTACK_HPP
#define CPP08_MUTANTSTACK_HPP
#include <stack>
#include <deque>


template<typename T>
class MutantStack: public std::stack<T> {
public:

	MutantStack(){};
	MutantStack(MutantStack & M): std::stack<T>(M) {};
	~MutantStack(){};
	MutantStack &operator=(const MutantStack & M)
	{
		if (this != &M)
			std::stack<T>::operator=(M);
		return (*this);
	};

	typedef typename std::deque<T, std::allocator<T> >::iterator iterator;
	typedef typename std::deque<T, std::allocator<T> >::const_iterator const_iterator;
	typedef typename std::deque<T, std::allocator<T> >::reverse_iterator reverse_iterator;
	typedef typename std::deque<T, std::allocator<T> >::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
private:

};




#endif //CPP08_MUTANTSTACK_HPP
