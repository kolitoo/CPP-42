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