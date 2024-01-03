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

void displayVector(const std::vector<t_nbr>& vec) {
    std::cout << "Vecteur : ";
    for (std::vector<t_nbr>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << it->nb << " ";
    }
    std::cout << std::endl;
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

void	PmergeMeVec::SortVector(void)
{
	ParseAndPutInVector();
	CreatePeer();
	for (unsigned int i = 0; i < _PeerArray.size(); i++)
	{
		std::cout <<_PeerArray[i].nb << " | ";
		if (_PeerArray[i].peer != NULL)
			std::cout <<_PeerArray[i].peer->nb << "---INDEX:" << _PeerArray[i].nb << std::endl;
		else
			std::cout << "---INDEX:" << _PeerArray[i].nb << std::endl;
	}
	std::cout << "\n----------\n";
	if (((_ac - 1) % 2 == 0))
		mergeSort(_PeerArray.begin(), _PeerArray.end());
	else
		mergeSort(_PeerArray.begin(), _PeerArray.end() - 1);
	_PeerArray.insert(_PeerArray.begin(), *_PeerArray[0].peer);
	_PeerArray[0].peer = NULL;
	_PeerArray[1].peer = NULL;
	for (unsigned int i = 0; i < _PeerArray.size(); i++)
	{
		std::cout <<_PeerArray[i].nb << " | ";
		if (_PeerArray[i].peer != NULL)
			std::cout <<_PeerArray[i].peer->nb << "---INDEX:" << _PeerArray[i].nb << std::endl;
		else
			std::cout << "---INDEX:" << _PeerArray[i].nb << std::endl;
	}
	std::cout << "\n";
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
		value.index = 0;
		if (value.nb > 2147483647)
			throw Overflow();
		_Array.push_back(value);
		i++;
	}
	std::vector<t_nbr> ArrayCopy = _Array;
	std::sort(ArrayCopy.begin(), ArrayCopy.end());
	for (size_t i = 1; i < ArrayCopy.size(); ++i)
	{
		if (ArrayCopy[i - 1].nb == ArrayCopy[i].nb)
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

std::vector<t_nbr>	PmergeMeVec::GetArray(void)
{
	return (_Array);
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
	return (nb < other.nb);
}

// struct_nbr& t_nbr::operator=(const struct_nbr* other)
// {
// 	if (this != other)
// 	{
// 		nb = other->nb;
// 		index = other->index;
// 		if (other->peer)
// 		{
// 			peer = new struct_nbr;
// 			*peer = *(other->peer);
// 		}
// 		else
// 			peer = NULL;
// 	}
// 	return *this;
// }