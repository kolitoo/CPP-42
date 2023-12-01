#pragma once

#include <iostream>
#include <stack>

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
	MutantStack<T>(void) { return ; }
	MutantStack<T>(const MutantStack<T>& substitue){ *this = substitue; }
	~MutantStack<T>(void){ return ; }

	MutantStack<T>&	operator=(const MutantStack<T>& substitue) { *this = substitue; return(*this); }

	private:

};