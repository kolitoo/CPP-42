#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <exception>

class Rpn
{
	public:
		Rpn(std::string av);
		~Rpn(void);

		void	ParseAv(void);
		void	SkipSpace(void);
		class	NonAutorizedChar : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};

	private:
		std::string	_av;
		std::string	_expression;
		std::stack<int>	_pile;
};
