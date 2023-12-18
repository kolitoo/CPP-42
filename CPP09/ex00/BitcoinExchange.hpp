#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <map>
#include <exception>
#include <cstdlib>
#include <limits>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream& file);
		BitcoinExchange(BitcoinExchange const& substitue);
		~BitcoinExchange(void);

		BitcoinExchange& operator=(BitcoinExchange const& substitue);

		void	PutDataInMap(void);
		void	printmap(void) const;
		void	CheckDate(void) const;
		void	CheckDay(std::string	day, std::string month) const;
		void	CheckYear(std::string	year) const;
		void	CheckValue(void) const;

		class	DayError : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	MonthError : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	YearError : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};
		class	ValueError : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};

	private:
		std::map<std::string, float>	_DataMap;
		std::ifstream&			_file;
		std::string			_date;
		float				_value;
};
