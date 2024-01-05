#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <algorithm>

typedef struct	struct_nbr
{
	unsigned int	nb;
	//unsigned int	index;
	int Jacobsthalvalue;
	struct_nbr	*peer;
	bool	operator<(const struct_nbr& other) const;
	// struct_nbr& operator=(const struct_nbr *other);
}t_nbr;

class PmergeMeVec
{
	public:
		PmergeMeVec(char **av, int ac);
		PmergeMeVec(const PmergeMeVec& substitue);
		~PmergeMeVec(void);

		PmergeMeVec&	operator=(const PmergeMeVec& substitue);

		void	SortVector(void);
		void	ParseAndPutInVector(void);
		void	CheckIfNumbers(std::string nb);
		void	CreatePeer(void);
		void	CreatePending(void);
		void	BinarySearch(void);
		void	CreateIntTab(void);
		std::vector<int>	GetArray(void);

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
		int			_ac;
		std::vector<t_nbr>	_Array;
		std::vector<t_nbr>	_PeerArray;
		std::vector<t_nbr>	_PendArray;
		std::vector<int>	_IntArray;
};