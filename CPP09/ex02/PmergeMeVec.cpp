#include "PmergeMeVec.hpp"

PmergeMeVec::PmergeMeVec(char **av): _av(av)
{
}

PmergeMeVec::PmergeMeVec(const PmergeMeVec& substitue)
{
	if (this != &substitue)
		*this = substitue;
}

PmergeMeVec::~PmergeMeVec(void)
{
}

PmergeMeVec&	PmergeMeVec::operator=(const PmergeMeVec& substitue)
{
	if (this != &substitue)
		*this = substitue;
	return (*this);
}

void	PmergeMeVec::ParseAndPutInVector(void)
{
	unsigned int i = 1;
	while (_av[i] != NULL)
	{
		std::string line = _av[i];
		CheckIfNumbers(line);
		try
		{
			int value = std::stoi(line);
			_Array.push_back(value);
		} catch (const std::out_of_range&)
		{
			throw Overflow();
		}
		i++;
	}
	for (std::vector<int>::const_iterator it = _Array.begin(); it != _Array.end(); ++it)
		std::cout << *it << " ";
	std::vector<int> ArrayCopy = _Array;
	std::sort(ArrayCopy.begin(), ArrayCopy.end());
	for (size_t i = 1; i < ArrayCopy.size(); ++i)
	{
		if (ArrayCopy[i - 1] == ArrayCopy[i])
			throw Doublon();
	}
}

void	PmergeMeVec::CheckIfNumbers(std::string nb)
{
	if (nb == "")
		throw NotANumber();
	for(unsigned int i = 0; i < nb.size(); i++)
	{
		if (nb[i] < '0' || nb[i] > '9')
			throw NotANumber();
	}
}

const char*	PmergeMeVec::NotANumber::what(void) const throw()
{
	return ("Error: Enter only Numbers.\n");
};

const char*	PmergeMeVec::Doublon::what(void) const throw()
{
	return ("Error: Enter Differents Numbers.\n");
};

const char*	PmergeMeVec::Overflow::what(void) const throw()
{
	return ("Error: Overflow.\n");
};
