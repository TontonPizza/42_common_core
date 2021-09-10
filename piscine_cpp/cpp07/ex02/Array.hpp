#ifndef SOURCE_CPP07_ARRAY_HPP
#define SOURCE_CPP07_ARRAY_HPP


#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

template <typename T>
class Array {
public:
						Array();
						Array(unsigned int n);
						Array(const Array & A);
						~Array();
	Array				&operator=(const Array & A);
	T	  				&operator[](unsigned int index);
	unsigned int		size() const;
private:
	T 					*array;
	unsigned int		 length;

};

template <typename T>
Array<T>::Array()
{
	this->array = new T[0];
	this->length = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->length = n;
}

template <typename T>
T & Array<T>::operator[](unsigned int index){

	if (index >= this->size())
		throw (std::out_of_range("index out of range"));
	return (this->array[index]);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
};

template <typename T>
Array<T>::Array(const Array<T> &A)
{
	this->array = new T[A.size()];
	this->length = 0;
	while (this->length < A.size())
	{
		this->array[this->length] = A.array[this->length];
		this->length++;
	}
}

template <typename T>
Array<T> & Array<T>::operator=(const Array<T> &A)
{
	this->array = new T[A.size()];
	this->length = 0;
	while (this->length < A.size())
	{
		this->array[this->length] = A[this->length];
		this->length++;
	}
	return  (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->length;
}

#endif //SOURCE_CPP07_ARRAY_HPP
