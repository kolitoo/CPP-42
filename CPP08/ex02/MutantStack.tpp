#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void)
{
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& substitue)
{
	*this = substitue;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	return ;
} 

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(const MutantStack<T>& substitue)
{
	*this = substitue;
	return(*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}