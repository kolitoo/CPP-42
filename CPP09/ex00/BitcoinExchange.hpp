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
#include <cctype>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::ifstream& bdd, std::ifstream& file);
		BitcoinExchange(BitcoinExchange const& substitue);
		~BitcoinExchange(void);

		BitcoinExchange& operator=(BitcoinExchange const& substitue);

		void	PutDataInMap(void);
		void	printmap(void) const;
		int	CheckDate(void);
		int	CheckDay(std::string	day, std::string month) const;
		int	CheckYear(std::string	year);
		int	CheckValue(void) const;
		void	DoTasks(void);
		int	PipeCheck(std::string line);
		void	DataAndValueCheck(void);
		void	CalculateExchange(void);
		int	CheckNumber(std::string value);
		std::string	trim(std::string& str);

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
		class	Emptybdd : public std::exception
		{
			public :
				virtual const char*	what() const throw();
		};

	private:
		std::multimap<std::string, float>	_DataMap;
		std::ifstream&			_bdd;
		std::ifstream&			_file;
		std::string			_date;
		float				_value;
		int				_bool;
};
