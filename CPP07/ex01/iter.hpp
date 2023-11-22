#pragma once

#include <iostream>

template <typename T>
void	iter(T *array, size_t lenght, void(*fct)(T))
{
	for (size_t i = 0; i < lenght; i++)
		fct(array[i]);
}
template <typename T>
void	printelem(T a)
{
	std::cout << "Element: " << a << std::endl;
}
