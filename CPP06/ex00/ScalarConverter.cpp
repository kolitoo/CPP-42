#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& substitue)
{
	(void)substitue;
	std::cout << "ScalarConverter constructor copy called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const& substitue)
{
	if (this != &substitue)
		*this = substitue;
	return (*this);
}

int	ScalarConverter::parsing(std::string arg)
{
	if (arg.size() == 1 && (arg[0] < '0' || arg[0] > '9'))
		return (1);
	else
	{
		size_t	i = 0;
		while (i < arg.size())
		{
			if (arg[i] == '-' && i!= 0)
				throw ScalarConverter::error();
			if (arg[i] == 'f' && (i != arg.size() - 1 || (arg[i - 1] < '0' || arg[i - 1] > '9')))
				throw ScalarConverter::error();
			if ((arg[i] < '0' || arg[i] > '9') && arg[i] != '.' && arg[i] != 'f' && arg[i] != '-')
				throw ScalarConverter::error();
			if (arg[i] == '.' && (i == arg.size() - 1 || i == 0 || arg[i + 1] == 'f' || arg[i + 1] == '.'))
				throw ScalarConverter::error();
			i++;
		}
		if (arg.find('f') != std::string::npos)
			return (2);
		if (arg.find('.') != std::string::npos)
			return (3);
		if (arg.find('f') == std::string::npos && arg.find('.') == std::string::npos)
			return (4);
	}
	return (0);
}

void	ScalarConverter::printChar(std::string arg)
{
	std::cout << "char : " << arg[0] << std::endl;
	std::cout << "int : " << static_cast<int>(arg[0]) << std::endl;
	std::cout << "float : " << std::fixed << static_cast<float>(arg[0]) << "f" << std::endl;
	std::cout << "double : " << std::fixed << static_cast<double>(arg[0]) << std::endl;
}

void	ScalarConverter::printInt(std::string arg)//overflow?
{
	int nb = atoi(arg.c_str());
	if (nb > 127)
		std::cout << "char : " << "Impossible" << std::endl;
	else if ((static_cast<char>(nb) < 32 || static_cast<char>(nb) > 126) && nb <= 127)
		std::cout << "char : " << "Non displayable" << std::endl;
	else
		std::cout << "char : " << static_cast<char>(nb) << std::endl;
	std::cout << "int : " << nb << std::endl;
	std::cout << "float : " << std::fixed << static_cast<float>(nb) << "f" << std::endl;
	std::cout << "double : " << std::fixed << static_cast<double>(nb) << std::endl;
}

void	ScalarConverter::printFloat(std::string arg)
{
	(void)arg;
}

void	ScalarConverter::printDouble(std::string arg)
{
	(void)arg;
}

void		ScalarConverter::convert(std::string arg)
{
	try
	{
		int	type = parsing(arg);
		void	(*tab_ptr_ft[4])(std::string) = {&printChar, &printFloat, &printDouble, &printInt};
		switch (type)
		{
			case 1:
				tab_ptr_ft[0](arg);
				break;
			case 2:
				tab_ptr_ft[1](arg);
				break;
			case 3:
				tab_ptr_ft[2](arg);
				break;
			case 4:
				tab_ptr_ft[3](arg);
				break;
			case 5:
				tab_ptr_ft[4](arg);
				break;
			default:
				break;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char*	ScalarConverter::error::what(void) const throw()
{
	return ("Invalid argument");
}