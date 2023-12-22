#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <vector>

class PmergeMeVec
{
	public:
		PmergeMeVec(char **av);
		PmergeMeVec(const PmergeMeVec& substitue);
		~PmergeMeVec(void);

		PmergeMeVec&	operator=(const PmergeMeVec& substitue);

		void	ParseAndPutInVector(void);
		void	CheckIfNumbers(std::string nb);

		class	NotANumber : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	Doublon : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	Overflow : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};

	private:
		char			**_av;
		std::vector<int>	_Array;
};