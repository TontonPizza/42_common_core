#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <limits>
# include <memory>
# include <iostream>
# include <stdexcept>
# include <string>
# include <sstream>
# include "iterator.hpp"
# include "enable_if.hpp"
# include "comparison.hpp"

namespace ft {


    template<class T, class Allocator = std::allocator<T> >
    class vector {
    public:
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef std::size_t size_type;
        typedef std::ptrdiff_t difference_type;
        typedef typename Allocator::reference reference;
        typedef typename Allocator::const_reference const_reference;
        typedef typename Allocator::pointer pointer;
        typedef typename Allocator::const_pointer const_pointer;
        typedef vectorIterator<T> iterator;
        typedef vectorConstIterator<T> const_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;

        vector() : _allocator(Allocator()), _size(0), _capacity(0), _array(NULL) {}
        explicit vector( const Allocator& alloc ) : _allocator(alloc), _size(0), _capacity(0), _array(NULL) {
        }

        explicit vector( size_type count,
                         const T& value = T(), const Allocator& alloc = Allocator()) {
            new (this) vector(alloc);
            this->assign(count, value);
        }

        template< class InputIt >
        vector( InputIt first, InputIt last, const Allocator& alloc = Allocator(),
                typename ft::enable_if<!is_integral<InputIt>::value>::type* = NULL) {
            new (this) vector(alloc);
            this->assign(first, last);
        }

        vector( const vector& other ) {
            new (this) vector(other.get_allocator());
            this->assign(other.begin(), other.end());
        }

        virtual ~vector() {
            this->clear();
            if (_capacity != 0)
                _allocator.deallocate(_array, _capacity);
            _capacity = 0;
            _size = 0;
        }

        vector& operator=( const vector& other ) {
            if (this != &other) {
                this->clear();
                if (other._size > _capacity)
                    this->reserve(other._size);
                _allocator = other._allocator;
                size_type i = 0;
                for(const_iterator it = other.begin(); it != other.end(); it++) {
                    _allocator.construct(_array + i++, *it);
                    _size++;
                }
            }
            return *this;
        }

        allocator_type get_allocator() const {
            return _allocator;
        }

        void assign( size_type count, const T& value ) {
            this->clear();
            this->reserve(count);
            for(size_type i = 0; i < count; i++) {
                _allocator.construct(_array + i, value);
                _size += 1;
            }
        }

        template< class InputIt >
        void assign( InputIt first, InputIt last,
                     typename ft::enable_if<!is_integral<InputIt>::value>::type* = NULL ) {
            this->clear();
            size_type count = 0;
            for(InputIt it = first; it != last; it++)
                count++;
            this->reserve(count);
            size_t i = 0;
            for(InputIt it = first; it != last; it++) {
                _allocator.construct(_array + i++, *it);
                _size += 1;
            }
        }

        reference at( size_type pos ) {
            if (pos >= this->size()) {
                std::stringstream ss;
                ss << "vector::_M_range_check: __n (which is " << pos << ")";
                ss << " >= this->size() (which is " << this->size() << ")";
                throw std::out_of_range(ss.str());
            }
            return _array[pos];
        }
        const_reference at( size_type pos ) const {
            if (pos >= this->size()) {
                std::stringstream ss;
                ss << "vector::_M_range_check: __n (which is " << pos << ")";
                ss << " >= this->size() (which is " << this->size() << ")";
                throw std::out_of_range(ss.str());
            }
            return _array[pos];
        }

        reference operator[]( size_type pos ) {
            return _array[pos];
        }
        const_reference operator[]( size_type pos ) const {
            return _array[pos];
        }

        reference front() {
            return _array[0];
        }
        const_reference front() const {
            return _array[0];
        }

        reference back() {
            return _size != 0 ? _array[_size - 1] : _array[0];
        }
        const_reference back() const {
            return _size != 0 ? _array[_size - 1] : _array[0];
        }

        iterator begin() {
            return iterator(_array);
        }
        const_iterator begin() const {
            return const_iterator(_array);
        }
        iterator end() {
            return iterator(_array + _size);
        }
        const_iterator end() const {
            return const_iterator(_array + _size);
        }
        reverse_iterator rbegin() {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(end());
        }
        reverse_iterator rend() {
            return reverse_iterator(begin());
        }
        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
        }

        bool empty() const {
            return _size == 0;
        }

        size_type size() const {
            return _size;
        }

        size_type max_size() const {
            return _allocator.max_size();
        }

        void reserve( size_type new_cap ) {
            if (new_cap > _capacity)
                _realloc(new_cap);
        }

        size_type capacity() const {
            return _capacity;
        }

        void clear() {
            if (this->empty())
                return ;
            for(size_type i = 0; i < _size; i++)
                _allocator.destroy(_array + i);
            _size = 0;
        }

        iterator insert( iterator pos, const T& value ) {
            size_type index = pos._node - _array;
            size_type pos_index = pos._node - _array;
            if (_size + 1 > _capacity)
                _realloc(_size == 0 ? 1 : _size * 2);
            pos = iterator(_array + pos_index);
            this->insert(pos, 1, value);
            return iterator(_array + index);
        }

        void insert( iterator pos, size_type count, const T& value ) {
            size_type index = pos._node - _array;
            if (_size + count > _capacity)
                _realloc(_size + count);
            this->_shift_right_elements(index, count);
            for (size_type i = index; i < count + index; i++)
                _allocator.construct(_array + i, value);
            _size += count;
        }

        template< class InputIt >
        void insert( iterator pos, InputIt first, InputIt last,
                     typename ft::enable_if<!is_integral<InputIt>::value>::type* = NULL) {
            size_type count = 0;
            size_type pos_index = pos._node - _array;
            for (InputIt it = first; it != last; it++)
                count++;
            int j = 0;
            while (_size + count > _capacity)
                _realloc(_size == 0 ? count : (_size + j++) * 2);
            pos = iterator(_array + pos_index);
            size_type i = 0;
            for(InputIt it = first; it != last; it++)
                insert(pos + i++, *it);
        }

        iterator erase( iterator pos ) {
            if (this->empty() || pos == end())
                return end();
            size_type index = pos._node - _array;
            _allocator.destroy(pos._node);
            for (size_type i = index; i < _size - 1; i++) {
                _allocator.construct(_array + i, _array[i + 1]);
                _allocator.destroy(_array + i + 1);
            }
            _size -= 1;
            return iterator(_array + index);
        }

        iterator erase( iterator first, iterator last ) {
            if (this->empty() || first == end())
                return end();
            size_type to_erase = 0;
            for(iterator it = first; it != last; it++)
                to_erase++;
            if (to_erase > _size)
                return end();
            size_type index_dst = first._node - _array;
            size_type index_src = last._node - _array;
            size_type nb_to_move = _size - to_erase;

            for (size_type i = 0; i < to_erase; i++)
                _allocator.destroy(first._node + i);
            for (size_type i = index_dst; i < nb_to_move; i++) {
                _allocator.construct(_array + i, _array[index_src]);
                _allocator.destroy(_array + index_src++);
            }
            _size -= to_erase;
            return iterator(_array + index_dst);
        }

        void push_back( const T& value ) {
            this->insert(end(), value);
        }

        void pop_back() {
            this->erase(--end());
        }

        void resize( size_type count, T value = T() ) {
            if (count < _size)
                this->erase(begin() + count, end());
            else {
                if (count + _size > _capacity)
                    _realloc(_size == 0 ? count : _size * 2);
                this->insert(end(), count - _size, value);
            }
        }

        void swap( vector& other ) {
            allocator_type tmp_allocator = other._allocator;
            size_type tmp_size = other._size;
            size_type tmp_capacity = other._capacity;
            pointer tmp_array = other._array;

            other._allocator = _allocator;
            _allocator = tmp_allocator;
            other._size = _size;
            _size = tmp_size;
            other._capacity = _capacity;
            _capacity = tmp_capacity;
            other._array = _array;
            _array = tmp_array;
        }

    private:

        void _shift_right_elements(const size_type& first_index, const size_type& count) {
            if (!this->empty()) {
                for (size_type i = _size; i > first_index; i--) {
                    _allocator.construct(_array + i + count - 1, _array[i - 1]);
                    _allocator.destroy(_array + i - 1);
                }
            }
        }

        void _realloc(size_type new_capacity) {
            pointer new_array = _allocator.allocate(new_capacity);
            for (size_type i = 0; i < _size; i++) {
                _allocator.construct(new_array + i, _array[i]);
                _allocator.destroy(_array + i);
            }
            if (_capacity != 0)
                _allocator.deallocate(_array, _capacity);
            _capacity = new_capacity;
            _array = new_array;
        }
        allocator_type _allocator;
        size_type _size;
        size_type _capacity;
        pointer _array;
    };

    template< class T, class Allocator >
    bool operator==( const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs ) {
        if (lhs.size() != rhs.size())
            return false;
        return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template< class T, class Allocator >
    bool operator!=( const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs ) {
        return !(lhs == rhs);
    }
    template< class T, class Allocator >
    bool operator<( const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs ) {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template< class T, class Allocator >
    bool operator<=( const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs ) {
        return (lhs < rhs || lhs == rhs);
    }
    template< class T, class Allocator >
    bool operator>( const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs ) {
        return !(lhs <= rhs);
    }
    template< class T, class Allocator >
    bool operator>=( const ft::vector<T, Allocator>& lhs, const ft::vector<T, Allocator>& rhs ) {
        return !(lhs < rhs);
    }

    template<class T, class Allocator>
    void swap( ft::vector<T, Allocator>& lhs, ft::vector<T, Allocator>& rhs ) {
        lhs.swap(rhs);
    }
}
#endif
