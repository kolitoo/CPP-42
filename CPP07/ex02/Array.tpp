#include "Array.hpp"

<template T>
Array<T>::Array(void)
{
	_Array - new T[0];
	_size = 0;
	std::cout << "Array constructor called" << std::endl;
}
}

<template T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_array = new T[n];
	for (int i = 0; i < n; i++)
		_array[i] = T();//met valeur par defaut peu importe le type
	std::cout << "Array constructor with size in setting called" << std::endl;
}

<template T>
Array<T>::Array(Array const& substitue)
{
	_size = substitue._size;
	delete[] _array;
	_array = new T[substitue._size];
	for (int i = 0; i < n; i++)
		_array[i] = substitue._array[i];
	std::cout << "Array copie constructor called" << std::endl;
}

<template T>
Array<T>::~Array(void)
{
	delete[] _array;
	std::cout << "Array destructor called" << std::endl;
}

<template T>
Array&	Array<T>::operator=(Array const& substitue)
{
	if (this != &substitue)
	{
			_size = substitue._size;
		delete[] _array;
		_array = new T[substitue._size];
		for (int i = 0; i < n; i++)
			_array[i] = substitue._array[i];
	}
	return (*this);
}

<template T>
T&	Array<T>::operator[](unsigned int i) const
{
	if (index >= size)
		throw forbidenindex();
	return (_array[i]);
}

<template T>
unsigned int	Array<T>::size() const
{
	return (_size);
}