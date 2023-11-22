#pragma once

#include <string>
#include <iostream>
#include <exception>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(Array const& substitue);
		Array(unsigned int n);
		~Array(void);

		Array&	operator=(Array const& substitue);
		T&	operator[](unsigned int i) const;

		unsigned int	size() const;

	privaye:
		T*		_array;
		unsigned int	_size;

		class	forbidenindex : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};