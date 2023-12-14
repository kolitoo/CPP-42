#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class   Span
{
	public:
		Span(unsigned int N);
		Span(const Span& substitue);
		~Span(void);

		Span&	operator=(Span const& substitue);

		void		addNumber(int Nb);
		void		mltpaddNumber(unsigned int Nb);
		int		shortestSpan(void);
		int		longestSpan(void);
		unsigned int	size(void) const;

		class	FullN : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
		class	NotFound : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

	private:
		unsigned int 		_MaxSize;
		std::vector<int>	_int_tab;

};