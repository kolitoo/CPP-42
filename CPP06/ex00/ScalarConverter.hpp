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
		void			convert(std::string test);
	private:
};