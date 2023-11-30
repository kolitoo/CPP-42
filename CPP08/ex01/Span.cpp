#include "Span.hpp"

Span::Span(unsigned int N)
{
	_MaxSize = N;
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(Span const& substitue)
{
	_MaxSize = substitue. _MaxSize;
	_int_tab = substitue._int_tab;
	std::cout << "Span copy constructor called" << std::endl;
}

Span::~Span(void)
{
	std::cout << "Span destructor called" << std::endl;
}

Span&	Span::operator=(Span const& substitue)
{ 
	if (this != &substitue)
	{
		_MaxSize = substitue. _MaxSize;
		_int_tab = substitue._int_tab;
	}
	return (*this);
};

void	Span::addNumber(int Nb)
{
	if (_int_tab.size() >=  _MaxSize)
		throw FullN();
	_int_tab.push_back(Nb);
}

void	Span::mltpaddNumber(unsigned int Nb)
{
	for (unsigned int i = 0; i < Nb; i++)
		addNumber(rand() % _MaxSize);
}

const char*	Span::FullN::what() const throw()
{
	return ("Error : can't add number because Span is full");
}

const char*	Span::NotFound::what() const throw()
{
	return ("Error : Span is void or only one number on it");
}

int Span::shortestSpan(void)
{
	int minSpan;
	if (_int_tab.size() < 2)
		throw NotFound();
	std::vector<int> sortedNumbers = _int_tab;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		minSpan = std::min(minSpan, span);
	}
	return (minSpan);
}

int Span::longestSpan(void)
{
	if (_int_tab.size() < 2)
		throw NotFound();
	int minElement = _int_tab[0];
	int maxElement = _int_tab[0];

	for (size_t i = 1; i < _int_tab.size(); ++i)
	{
		if (_int_tab[i] < minElement)
			minElement = _int_tab[i];
		else if (_int_tab[i] > maxElement)
			maxElement = _int_tab[i];
	}
	return (maxElement - minElement);
}

unsigned int	Span::size(void) const
{
	return (_int_tab.size());
}