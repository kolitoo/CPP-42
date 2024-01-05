#include "PmergeMeVec.hpp"

PmergeMeVec::PmergeMeVec(char **av, int ac): _av(av), _ac(ac)
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

int Jacobsthal(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void	mergeSort(std::vector<t_nbr>::iterator iter1, std::vector<t_nbr>::iterator iter2)
{
	size_t size = iter2 - iter1;
	std::vector<t_nbr>::iterator iterMiddle = iter1 + size / 2;

	if (size > 1)
	{
		mergeSort(iter1, iterMiddle);
		mergeSort(iterMiddle, iter2);
		std::inplace_merge(iter1, iterMiddle, iter2);
	}
}

void	PmergeMeVec::CreatePending(void)
{
	// unsigned int	index = 1;
	for (unsigned int i = 0; i < _PeerArray.size(); i++)
	{
		if ((_ac - 1) % 2 != 0 && i == _PeerArray.size() - 1)
		{
			//_PeerArray[i].index = index;
			_PendArray.push_back(_PeerArray[i]);
			_PeerArray.pop_back();
		}
		else
		{
			// _PeerArray[i].index = index;
			if (_PeerArray[i].peer != NULL)
			{
			//	_PeerArray[i].peer->index = index;
				_PendArray.push_back(*_PeerArray[i].peer);
				_PeerArray[i].peer = NULL;
			}
			//index++;
		}
	}
}

void	PmergeMeVec::BinarySearch(void)
{
	for (std::vector<t_nbr>::iterator it = _PendArray.begin(); it != _PendArray.end(); ++it)
	{
		t_nbr temp;
		//temp.index = it->index;
		temp.nb = it->nb;
		temp.peer = NULL;
		//temp.Jacobsthalvalue = it->Jacobsthalvalue;//A L AIDE

		_PeerArray.insert(std::upper_bound(_PeerArray.begin(), _PeerArray.end(), temp), temp);
	}
}

void	PmergeMeVec::CreateIntTab(void)
{
	for (std::vector<t_nbr>::iterator it = _PeerArray.begin(); it != _PeerArray.end(); it++)
	{
		_IntArray.push_back(it->nb);
	}
}

void	PmergeMeVec::SortVector(void)
{
	ParseAndPutInVector();
	CreatePeer();
	if (((_ac - 1) % 2 == 0))
		mergeSort(_PeerArray.begin(), _PeerArray.end());
	else
		mergeSort(_PeerArray.begin(), _PeerArray.end() - 1);
	if (_ac > 2)
	{
		_PeerArray.insert(_PeerArray.begin(), *_PeerArray[0].peer);
		_PeerArray[0].peer = NULL;
		_PeerArray[1].peer = NULL;
	}
	CreatePending();
	BinarySearch();
	std::cout << std::endl;
	CreateIntTab();
}

void	PmergeMeVec::CreatePeer(void)
{
	for (unsigned int i = 0; i < _Array.size(); i+=2)
	{
		if (i == _Array.size() - 1)
		{
			_Array[i].peer = NULL;
			_PeerArray.push_back(_Array[i]);
		}
		else
		{
			_Array[i].peer = &_Array[i + 1];
			_Array[i + 1].peer = &_Array[i];
			if (_Array[i].nb > _Array[i].peer->nb)
				_PeerArray.push_back(_Array[i]);
			else
				_PeerArray.push_back(_Array[i + 1]);
		}
		//index++;
	}
}

void	PmergeMeVec::ParseAndPutInVector(void)
{
	unsigned int i = 1;
	while (_av[i] != NULL)
	{
		std::string line = _av[i];
		CheckIfNumbers(line);
		t_nbr	value;
		value.nb = std::atoi(line.c_str());
		//value.index = 0;
		value.Jacobsthalvalue = Jacobsthal(value.nb);
		if (value.nb > 2147483647)
			throw Overflow();
		_Array.push_back(value);
		i++;
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

std::vector<int>	PmergeMeVec::GetArray(void)
{
	return (_IntArray);
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

bool	t_nbr::operator<(const struct_nbr& other) const
{
	return(nb < other.nb);
	//return Jacobsthalvalue < other.Jacobsthalvalue;//ALORS PEU ETRE ?
}