#pragma once

#include <iostream>
#include <string>
#include <exception>

class PmergeMeVec
{
	public:
		PmergeMeVec(char **av);
		PmergeMeVec(const PmergeMeVec& substitue);
		~PmergeMeVec(void);

		PmergeMeVec&	operator=(const PmergeMeVec& substitue);


	private:
		char	**_av;
};