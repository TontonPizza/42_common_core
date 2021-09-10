#ifndef STACK_HPP
# define STACK_HPP
# include "vector.hpp"

namespace ft {
    template<class T, class Container = vector<T> >
    class stack {
    public:
        typedef Container container_type;
        typedef typename Container::value_type value_type;
        typedef typename Container::size_type size_type;
        typedef typename Container::reference reference;
        typedef typename Container::const_reference const_reference;

        explicit stack( const Container& cont = Container() ) : _c(cont) {}
        stack(const stack& src) { *this = src; }
        stack& operator=(const stack& rhs) {
            if (this != &rhs)
                _c = rhs._c;
            return *this;
        }
        virtual ~stack() {}

        reference top() { return _c.back(); }
        const_reference top() const { return _c.back(); }

        bool empty() const { return _c.empty(); }
        size_type size() const { return _c.size(); }

        void push( const value_type& value ) { _c.push_back(value); }
        void pop() { _c.pop_back(); }
//        void swap( stack& other ) {	_c.swap(other._c); }


    protected:
        Container _c;
    private:

        friend bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
            return lhs._c == rhs._c;
        }
        friend bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
            return lhs._c != rhs._c;
        }
        friend bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
            return lhs._c < rhs._c;
        }
        friend bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
            return lhs._c <= rhs._c;
        }
        friend bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
            return lhs._c > rhs._c;
        }
        friend bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs ) {
            return lhs._c >= rhs._c;
        }

        void swap( stack<T,Container>& lhs, stack<T,Container>& rhs ) { lhs.swap(rhs); }

    };
}
#endif
