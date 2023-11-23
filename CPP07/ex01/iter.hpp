#pragma once

#include <iostream>

template <typename T, typename F>
void	iter(T *array, size_t lenght, F fct)
{
	for (size_t i = 0; i < lenght; i++)
		fct(array[i]);
}
template <typename T>
void	printelem(T a)
{
	std::cout << "Element: " << a << std::endl;
}
