#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& substitue);
		~ScalarConverter(void);

		ScalarConverter&	operator=(ScalarConverter const& substitue);

		static std::string	parsing(std::string arg);
		static void	convert(std::string test);
	private:
};