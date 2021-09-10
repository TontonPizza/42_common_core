#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <limits>
# include <memory>
# include <iostream>
# include <stdexcept>
# include <string>
# include <sstream>
# include "base_structures.hpp"

namespace ft {
    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

    template< class Category,
            class T,
            class Distance = std::ptrdiff_t,
            class Pointer = T*,
            class Reference = T& >
    struct iterator {
        typedef Distance difference_type;
        typedef T value_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    template< class Iter >
    struct iterator_traits {
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::value_type value_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    template< class T >
    struct iterator_traits<T*> {
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };

    template< class Iter >
    class reverse_iterator {
    public:
        typedef Iter iterator_type;
        typedef typename iterator_traits<Iter>::difference_type difference_type;
        typedef typename iterator_traits<Iter>::value_type value_type;
        typedef typename iterator_traits<Iter>::reference reference;
        typedef typename iterator_traits<Iter>::pointer pointer;
        typedef typename iterator_traits<Iter>::iterator_category iterator_category;

        reverse_iterator() : _current() {}
        explicit reverse_iterator( iterator_type x ) : _current(x) {}
        template< class U >
        reverse_iterator( const reverse_iterator<U>& other ) : _current(other.base()) {}
        template< class U >
        reverse_iterator& operator=( const reverse_iterator<U>& other ) {
            _current = other.base();
            return *this;
        }
        virtual ~reverse_iterator() {}

        iterator_type base() const {
            return _current;
        }

        reference operator*() const {
            Iter tmp = _current;
            return *--tmp;
        }
        pointer operator->() const {
            return &(this->operator*());
        }

        reference operator[]( difference_type n ) const {
            return base()[- n - 1];
        }

        reverse_iterator& operator++() {
            _current--;
            return *this;
        }
        reverse_iterator& operator--() {
            _current++;
            return *this;
        }
        reverse_iterator operator++( int ) {
            reverse_iterator tmp = *this;
            _current--;
            return tmp;
        }
        reverse_iterator operator--( int ) {
            reverse_iterator tmp = *this;
            _current++;
            return tmp;
        }
        reverse_iterator operator+( difference_type n ) const {
            return reverse_iterator( base() - n );
        }
        reverse_iterator operator-( difference_type n ) const {
            return reverse_iterator( base() + n );
        }
        reverse_iterator& operator+=( difference_type n ) {
            _current -= n;
            return *this;
        }
        reverse_iterator& operator-=( difference_type n ) {
            _current += n;
            return *this;
        }

    protected:
        Iter _current;
    };

    template< class Iterator1, class Iterator2 >
    bool operator==( const reverse_iterator<Iterator1>& lhs,
                     const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() == rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator!=( const reverse_iterator<Iterator1>& lhs,
                     const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() != rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator<( const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() > rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator<=( const reverse_iterator<Iterator1>& lhs,
                     const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() >= rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator>( const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() < rhs.base();
    }
    template< class Iterator1, class Iterator2 >
    bool operator>=( const reverse_iterator<Iterator1>& lhs,
                     const reverse_iterator<Iterator2>& rhs ) {
        return lhs.base() <= rhs.base();
    }

    template< class Iter >
    reverse_iterator<Iter>
    operator+( typename reverse_iterator<Iter>::difference_type n,
               const reverse_iterator<Iter>& it ) {
        return reverse_iterator<Iter>(it.base() - n);
    }

    template< class Iterator1, class Iterator2 >
    typename reverse_iterator<Iterator1>::difference_type
    operator-( const reverse_iterator<Iterator1>& lhs,
               const reverse_iterator<Iterator2>& rhs ) {
        return rhs.base() - lhs.base();
    }

    template< class T >
    class vectorIterator : public ft::iterator<ft::random_access_iterator_tag, T,
            std::ptrdiff_t , T*, T&>  {
    public:
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef ft::random_access_iterator_tag iterator_category;

        vectorIterator() {}
        vectorIterator(T* node) : _node(node) {}
        vectorIterator(const vectorIterator& src) { *this = src; }
        vectorIterator& operator=(const vectorIterator& rhs) {
            if (this != &rhs)
                this->_node = rhs._node;
            return *this;
        }
        virtual ~vectorIterator() {}

        reference operator*() const {
            return *_node;
        }
        pointer operator->() const {
            return _node;
        }
        friend difference_type operator-(const vectorIterator& lhs,
                                         const vectorIterator& rhs) {
            return lhs._node - rhs._node;
        }
        reference operator[](int n) const {
            return *(_node + n);
        }

        friend bool operator==(const vectorIterator& lhs, const vectorIterator& rhs) {
            return lhs._node == rhs._node;
        }
        friend bool operator!=(const vectorIterator& lhs, const vectorIterator& rhs) {
            return lhs._node != rhs._node;
        }
        friend bool operator<(const vectorIterator& lhs, const vectorIterator& rhs) {
            return lhs._node < rhs._node;
        }
        friend bool operator<=(const vectorIterator& lhs, const vectorIterator& rhs) {
            return lhs._node <= rhs._node;
        }
        friend bool operator>(const vectorIterator& lhs, const vectorIterator& rhs) {
            return lhs._node > rhs._node;
        }
        friend bool operator>=(const vectorIterator& lhs, const vectorIterator& rhs) {
            return lhs._node >= rhs._node;
        }

        vectorIterator& operator++() {
            this->_node++;
            return *this;
        }
        vectorIterator operator++(int) {
            vectorIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        vectorIterator& operator--() {
            this->_node--;
            return *this;
        }
        vectorIterator operator--(int) {
            vectorIterator tmp = *this;
            --(*this);
            return tmp;
        }
        vectorIterator& operator+=(int n) {
            this->_node += n;
            return *this;
        }
        vectorIterator operator+(difference_type n) const {
            return vectorIterator(this->_node + n);
        }
        friend vectorIterator operator+(difference_type n,
                                        const vectorIterator& rhs) {
            return vectorIterator(rhs._node + n);
        }

        vectorIterator& operator-=(int n) {
            this->_node -= n;
            return *this;
        }
        vectorIterator operator-(int n) const {
            return vectorIterator(this->_node - n);
        }

        T* _node;
    };


    template< class T >
    class vectorConstIterator : public ft::iterator<ft::random_access_iterator_tag, T,
            std::ptrdiff_t , T*, T&>  {
    public:
        typedef std::ptrdiff_t difference_type;
        typedef const T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef ft::random_access_iterator_tag iterator_category;

        vectorConstIterator() {}
        vectorConstIterator(T* node) : _node(node) {}
        vectorConstIterator(const vectorConstIterator& src) { *this = src; }
        vectorConstIterator(const vectorIterator<T>& src) : _node(src._node) {}
        vectorConstIterator& operator=(const vectorConstIterator& rhs) {
            if (this != &rhs)
                this->_node = rhs._node;
            return *this;
        }
        virtual ~vectorConstIterator() {}

        reference operator*() const {
            return *_node;
        }
        pointer operator->() const {
            return _node;
        }
        friend difference_type operator-(const vectorConstIterator& lhs,
                                         const vectorConstIterator& rhs) {
            return lhs._node - rhs._node;
        }
        reference operator[](int n) const {
            return *(_node + n);
        }

        friend bool operator==(const vectorConstIterator& lhs, const vectorConstIterator& rhs) {
            return lhs._node == rhs._node;
        }
        friend bool operator!=(const vectorConstIterator& lhs, const vectorConstIterator& rhs) {
            return lhs._node != rhs._node;
        }
        friend bool operator<(const vectorConstIterator& lhs, const vectorConstIterator& rhs) {
            return lhs._node < rhs._node;
        }
        friend bool operator<=(const vectorConstIterator& lhs, const vectorConstIterator& rhs) {
            return lhs._node <= rhs._node;
        }
        friend bool operator>(const vectorConstIterator& lhs, const vectorConstIterator& rhs) {
            return lhs._node > rhs._node;
        }
        friend bool operator>=(const vectorConstIterator& lhs, const vectorConstIterator& rhs) {
            return lhs._node >= rhs._node;
        }

        vectorConstIterator& operator++() {
            this->_node++;
            return *this;
        }
        vectorConstIterator operator++(int) {
            vectorConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        vectorConstIterator& operator--() {
            this->_node--;
            return *this;
        }
        vectorConstIterator operator--(int) {
            vectorConstIterator tmp = *this;
            --(*this);
            return tmp;
        }
        vectorConstIterator& operator+=(int n) {
            this->_node += n;
            return *this;
        }
        vectorConstIterator operator+(difference_type n) const {
            return vectorConstIterator(this->_node + n);
        }
        friend vectorConstIterator operator+(difference_type n,
                                             const vectorConstIterator& rhs) {
            return vectorConstIterator(rhs._node + n);
        }

        vectorConstIterator& operator-=(int n) {
            this->_node -= n;
            return *this;
        }
        vectorConstIterator operator-(int n) const {
            return vectorConstIterator(this->_node - n);
        }

        T* _node;
    };

    template< class T >
    class mapIterator : public ft::iterator<bidirectional_iterator_tag,
            T, std::ptrdiff_t , T*, T&> {
    public:
        typedef std::ptrdiff_t difference_type;
        typedef T value_type;
        typedef T* pointer;
        typedef T& reference;
        typedef bstree<T> bstree;
        typedef ft::bidirectional_iterator_tag iterator_category;

        mapIterator() {}
        mapIterator(bstree* node) : _node(node) {}
        mapIterator(const mapIterator& src) { *this = src; }
        mapIterator& operator=(const mapIterator& rhs) {
            if (this != &rhs)
                this->_node = rhs._node;
            return *this;
        }
        virtual ~mapIterator() {}

        reference operator*() const {
            return this->_node->content;
        }
        pointer operator->() const {
            return &(this->_node->content);
        }
        friend bool operator==(const mapIterator& lhs, const mapIterator& rhs) {
            return (lhs._node == rhs._node);
        }
        friend bool operator!=(const mapIterator& lhs, const mapIterator& rhs) {
            return (lhs._node != rhs._node);
        }

        mapIterator& operator++() {
            this->_node = _find_next(this->_node);
            return *this;
        }
        mapIterator operator++(int) {
            mapIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        mapIterator& operator--() {
            this->_node = _find_prev(this->_node);
            return *this;
        }
        mapIterator operator--(int) {
            mapIterator tmp = *this;
            --(*this);
            return tmp;
        }

        bstree* _node;
    };

    template< class T >
    class mapConstIterator : public ft::iterator<bidirectional_iterator_tag,
            T, std::ptrdiff_t , T*, T&> {
    public:
        typedef std::ptrdiff_t difference_type;
        typedef const T value_type;
        typedef const T* pointer;
        typedef const T& reference;
        typedef bstree<T> bstree;
        typedef ft::bidirectional_iterator_tag iterator_category;

        mapConstIterator() {}
        mapConstIterator(const mapConstIterator& src) { *this = src; }
        mapConstIterator(bstree* node) : _node(node){}
        mapConstIterator(const mapIterator<T>& src) : _node(src._node) {}
        mapConstIterator& operator=(const mapConstIterator& rhs) {
            if (this != &rhs)
                this->_node = rhs._node;
            return *this;
        }
        virtual ~mapConstIterator() {}

        reference operator*() const {
            return this->_node->content;
        }
        pointer operator->() const {
            return &(this->_node->content);
        }
        friend bool operator==(const mapConstIterator& lhs, const mapConstIterator& rhs) {
            return (lhs._node == rhs._node);
        }
        friend bool operator!=(const mapConstIterator& lhs, const mapConstIterator& rhs) {
            return (lhs._node != rhs._node);
        }

        mapConstIterator& operator++() {
            this->_node = _find_next(this->_node);
            return *this;
        }
        mapConstIterator operator++(int) {
            mapConstIterator tmp = *this;
            ++(*this);
            return tmp;
        }
        mapConstIterator& operator--() {
            this->_node = _find_prev(this->_node);
            return *this;
        }
        mapConstIterator operator--(int) {
            mapConstIterator tmp = *this;
            --(*this);
            return tmp;
        }

        bstree* _node;
    };

}

#endif
