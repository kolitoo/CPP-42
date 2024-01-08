#pragma once

#include "PmergeMeVec.hpp"
#include <deque>

class PmergeMeDeque
{
	public:
		PmergeMeDeque(char** av, int ac);
		PmergeMeDeque(const PmergeMeDeque& substitue);
		~PmergeMeDeque(void);
		PmergeMeDeque& operator=(const PmergeMeDeque& substitue);
		void SortDeque(void);
		void ParseAndPutInDeque(void);
		void CheckIfNumbers(std::string nb);
		void CreatePeer(void);
		void CreatePending(void);
		void BinarySearch(void);
		void CreateIntTab(void);
		std::deque<int> GetArray(void);

		class NotANumber : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class Overflow : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		char** _av;
		int _ac;
		std::deque<t_nbr> _Array;
		std::deque<t_nbr> _PeerDeque;
		std::deque<t_nbr> _PendDeque;
		std::deque<int> _IntDeque;
};
