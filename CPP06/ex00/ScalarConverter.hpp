#pragma once

#include <iostream>
#include <string>
#include <exception>

class ScalarConverter
{
	public:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const& substitue);
		~ScalarConverter(void);

		ScalarConverter&	operator=(ScalarConverter const& substitue);

		static int	parsing(std::string arg);
		static void	convert(std::string test);
		static void	printChar(std::string arg);
		static void	printInt(std::string arg);
		static void	printFloat(std::string arg);
		static void	printDouble(std::string arg);
		class error : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
};