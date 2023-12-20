#include "RPN.hpp"

Rpn::Rpn(std::string av): _av(av)
{
}

Rpn::~Rpn(void)
{
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
		else
		{
			if (i > 1)
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
	std::cout << _av << std::endl;
}

void	Rpn::CheckAndDeleteSpace(void)
{
	for (unsigned int i = 1; i <= _av.length() - 1; i++)
	{
		if ((i == _av.length() - 1) && _av[i] != ' ')
			break ;
		if (_av[i] != ' ' && (_av[i - 1] != ' ' || _av[i + 1] != ' '))
		{
			throw SpaceProblem();
		}
	}
	for (unsigned int i = 1; i <= _av.length() - 1; i++)
	{
		if (_av[i] == ' ' && (_av[i - 1] == ' ' || _av[i + 1] == ' '))
			throw SpaceProblem();
	}
	unsigned int i = 0;
	for (unsigned int j = 0; j < _av.length(); j++)
	{
		if (_av[j] != ' ')
			_av[i++] = _av[j];
	}
	_av.resize(i);
}

void	Rpn::CheckOperators(void)
{
	unsigned int i = -1;
	unsigned int countOpe = 0;
	unsigned int countDigit = 0;
	while (++i <= _av.length() - 1)
	{
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
	return ("Error: Wrong number of operators.\n");
};

const char*	Rpn::NonAutorizedChar::what(void) const throw()
{
	return ("Error: Non Autorized Character.\n");
};

const char*	Rpn::SpaceProblem::what(void) const throw()
{
	return ("Error: Space Problem.\n");
};

const char*	Rpn::TwoFirstNb::what(void) const throw()
{
	return ("Error: Expression should start by 2 numbers.\n");
};
