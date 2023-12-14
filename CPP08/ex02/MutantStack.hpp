#pragma once

#include <iostream>
#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack<T>(void);
		MutantStack<T>(const MutantStack<T>& substitue);
		~MutantStack<T>(void);

		MutantStack<T>&	operator=(const MutantStack<T>& substitue);

		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"