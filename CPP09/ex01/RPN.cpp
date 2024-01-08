#include "RPN.hpp"

Rpn::Rpn(std::string av): _av(av)
{
}

Rpn::~Rpn(void)
{
}

Rpn::Rpn(Rpn const& substitue)
{
	if (this != &substitue)
		*this = substitue;
}

Rpn& Rpn::operator=(Rpn const& substitue)
{
	if (this != &substitue)
		*this = substitue;
	return (*this);
}

int	Rpn::Calculate(int nb1, int nb2, char c)
{
	if (c == '+')
		return (nb1 + nb2);
	if (c == '-')
		return (nb1 - nb2);
	if (c == '*')
		return (nb1 * nb2);
	if (c == '/')
		return (nb1 / nb2);
	return (-1);
}

void	Rpn::Execute(void)
{
	int	result = 0;
	for (unsigned int i = 0; i <= _av.length() - 1; i++)
	{
		if (_av[i] >= '0' && _av[i] <= '9')
		{
			_pile.push(_av[i] - '0');
		}
		else if (_av[i] == '-' && (_av[i + 1] >= '0' && _av[i + 1] <= '9'))
		{
			_pile.push((_av[i + 1] - '0') * -1);
			i++;
		}
		else if (_av[i] != ' ')
		{
			if (_pile.size() > 1)
			{
				int nb2 = _pile.top();
				_pile.pop();
				int nb1 = _pile.top();
				_pile.pop();
				result = Calculate(nb1, nb2, _av[i]);
				_pile.push(result);
			}
			else
				throw TwoFirstNb();
		}
	}
	std::cout << "Le resultat est: " << result << std::endl;
}

void	Rpn::ParseAv(void)
{
	for (unsigned int i = 0; i <= _av.length() - 1; i++)
	{
		if (!std::isdigit(_av[i]) && !std::isspace(_av[i]) && _av[i] != '+' && _av[i]!= '-' && _av[i] != '/' && _av[i] != '*')
			throw NonAutorizedChar();
	}
	CheckAndDeleteSpace();
	CheckOperators();
}

void	Rpn::CheckAndDeleteSpace(void)
{
	for (unsigned int i = 1; i <= _av.length() - 1; i++)
	{
		if ((i == _av.length() - 1) && _av[i] != ' ')
			break ;
		if (_av[i] != ' ' && (_av[i - 1] != ' ' || _av[i + 1] != ' '))
		{
			if ((_av[i] == '-' && (_av[i + 1] >= '0' && _av[i + 1] <= '9')) || ((_av[i] >= '0' && _av[i] <= '9') && _av[i - 1] == '-'))
				continue ;
			std::cout << _av[i] << std::endl;
			throw SpaceProblem();
		}
	}
}

void	Rpn::CheckOperators(void)
{
	unsigned int i = -1;
	unsigned int countOpe = 0;
	unsigned int countDigit = 0;
	while (++i <= _av.length() - 1)
	{
		if ((_av[i] == '-' && (_av[i + 1] >= '0' && _av[i + 1] <= '9')) || _av[i] == ' ')
			continue ;
		if (_av[i] >= '0' && _av[i] <= '9')
			countDigit++;
		else
			countOpe++;
	}
	if ((countDigit - 1) != countOpe || countOpe == 0)
		throw WrongOpeNumber();
}

const char*	Rpn::WrongOpeNumber::what(void) const throw()
{
	return ("Error: Wrong number of numbers/operators.\n");
};

const char*	Rpn::NonAutorizedChar::what(void) const throw()
{
	return ("Error: Non Autorized Character.\n");
};

const char*	Rpn::SpaceProblem::what(void) const throw()
{
	return ("Error: Space/Number Problem.\n");
};

const char*	Rpn::TwoFirstNb::what(void) const throw()
{
	return ("Error: Expression should start by 2 numbers.\n");
};
