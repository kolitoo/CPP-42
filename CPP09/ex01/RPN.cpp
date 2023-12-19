#include "RPN.hpp"

Rpn::Rpn(std::string av): _av(av)
{
}

Rpn::~Rpn(void)
{
}

void	Rpn::ParseAv(void)
{
	for (unsigned int i = 0; _av[i]; i++)
	{
		if (!std::isdigit(_av[i]) && !std::isspace(_av[i]) && _av[i] != '+' && _av[i]!= '-' && _av[i] != '/' && _av[i] != '*')
			throw NonAutorizedChar();
	}
	SkipSpace();
}

void	Rpn::SkipSpace(void)
{
	unsigned int i = 0;
	unsigned int j = 0;
	std::cout << _av << std::endl;
	if (_av[i] == ' ')
		i++;
	while (_av[i])
	{
		_expression[j] = _av[i];
		i += 2;
		j++;
	}
	std::cout << _expression << std::endl;
}

const char*	Rpn::NonAutorizedChar::what(void) const throw()
{
	return ("Error: Non Autorized Character.\n");
};
