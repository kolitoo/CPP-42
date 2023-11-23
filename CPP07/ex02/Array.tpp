#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	_array = new T[0];
	_size = 0;
	std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_array[i] = T();//met valeur par defaut peu importe le type
	std::cout << "Array constructor with size in setting called" << std::endl;
}

template <typename T>
Array<T>::Array(Array const& substitue)
{
	_size = substitue._size;
	_array = new T[substitue._size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = substitue._array[i];
	std::cout << "Array copy constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _array;
	std::cout << "Array destructor called" << std::endl;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const& substitue)
{
	if (this != &substitue)
	{
		if (_array != NULL)
			delete[] _array;
		_size = substitue._size;
		_array = new T[substitue._size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = substitue._array[i];
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int i) const
{
	if (i >= _size)
		throw forbidenindex();
	return (_array[i]);
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template <typename T>
const char*	Array<T>::forbidenindex::what(void) const throw()
{
	return ("Forbidden Index");
}