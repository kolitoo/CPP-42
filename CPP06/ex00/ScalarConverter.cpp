#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& substitue)
{
	// if (this != &substitue)
	// 	*this = substitue;
	(void)substitue;
	std::cout << "ScalarConverter constructor copy called" << std::endl;
	// return (*this);
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

std::string	ScalarConverter::parsing(std::string arg)
{
	std::string type;

	std::cout << arg.size() << std::endl;
	if (arg.size() == 1 && (arg[0] < '0' || arg[0] > '9'))
		return ("CHAR");
	else if (arg.find('f') != std::string::npos)
		return ("FLOAT");
	else if (arg.find('.') != std::string::npos)
		return ("DOUBLE");
	else if (arg.find('f') == std::string::npos && arg.find('.') == std::string::npos)
		return ("INT");
	return ("ERROR");
}

void		ScalarConverter::convert(std::string arg)
{
	std::string	type = parsing(arg);

	std::cout << type << std::endl;
}