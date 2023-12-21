#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <exception>
#include <cstdlib>

class Rpn
{
	public:
		Rpn(std::string av);
		Rpn(Rpn const& substitue);
		~Rpn(void);

		Rpn& operator=(Rpn const& substitue);

		void	ParseAv(void);
		void	CheckAndDeleteSpace(void);
		void	CheckOperators();
		void	Execute();
		int	Calculate(int nb1, int nb2, char c);
		class	NonAutorizedChar : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	SpaceProblem : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	WrongOpeNumber : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	TwoFirstNb : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};

	private:
		std::string	_av;
		std::stack<int>	_pile;
};
