#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream& bdd, std::ifstream& file): _bdd(bdd), _file(file)
{
	_bool = 0;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& substitue): _bdd(substitue._bdd), _file(substitue._file)
{
	if (this != &substitue)
		_DataMap = substitue._DataMap;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& substitue)
{
	if (this != &substitue)
		*this = substitue;
	return (*this);
}

void	BitcoinExchange::DoTasks(void)
{
	PutDataInMap();//Met bdd dans conteneur Map.
	DataAndValueCheck();//Parse le input file et calcule
}

void	BitcoinExchange::DataAndValueCheck(void)
{
	_bool = 1;
	if (_DataMap.empty())
		throw Emptybdd();
	std::string	line;
	while (std::getline(_file, line))
	{
		if (PipeCheck(line) == 1)
			continue ;
		std::istringstream iss(line);
		if (std::getline(iss, _date, '|'))
		{
			std::string	value;
			if (std::getline(iss, value))
			{
				_date = trim(_date);
				value = trim(value);
				if (_date == "date" && value == "value")
					continue;
				if (CheckNumber(value) == 1)
					continue ;
				_value = atof(value.c_str());
				if (CheckDate() == 1)
					continue ;
				if (CheckValue() == 1)
					continue ;
				CalculateExchange();
			}
		}
	}
}

int	BitcoinExchange::CheckNumber(std::string value)
{
	for (unsigned int i = 0; value[i]; i++)
	{
		if (!std::isdigit(value[i]))
		{
			if (value[i] != '.' && value[i] != ',')
			{
				std::cout << "Error: Not only number in the value." << std::endl;
				return (1);
			}
		}
	}
	return (0);
}

void	BitcoinExchange::CalculateExchange(void)
{
	float	result = 0;
	std::multimap<std::string, float>::const_iterator it = _DataMap.begin();
	if (_date < it->first)
		return (std::cout << "Error: Date smaller than smallest of bdd." << std::endl, (void)0);
	while (it != _DataMap.end() && it->first <= _date)
		it++;
	it--;
	result = _value * it->second;
	std::cout << std::setprecision(2) << std::fixed << _date << " => " << _value << " = " << result << std::endl;
}

int	BitcoinExchange::PipeCheck(std::string line)
{
	size_t	pipePos = line.find('|');
	if (pipePos == std::string::npos)
		return ((std::cout << "Error : bad input ==> \"" << line << "\"" << std::endl), 1);
	if (pipePos > 0 && line[pipePos - 1] == ' ')
	{
		if (pipePos < line.size() - 1 && line[pipePos + 1] == ' ')
			return (0);
		else
			return ((std::cout << "Error : bad input ==> " << line << std::endl), 1);
	}
	else
		return ((std::cout << "Error : bad input ==> " << line << std::endl), 1);
	return (0);
}

void	BitcoinExchange::PutDataInMap(void)
{
	_bool = 0;
	std::string	line;
	while (std::getline(_bdd, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, _date, ','))
		{
			std::string	value;
			if (std::getline(iss, value))
			{
				if (_date == "date" && value == "exchange_rate")
					continue;
				std::istringstream(value) >> _value;
				CheckDate();
				CheckValue();
				_DataMap.insert(std::make_pair(_date, _value));
				// _DataMap[_date] = _value;
			}
		}
	}
}

int	BitcoinExchange::CheckValue(void) const
{
	if (_bool == 0)
	{
		if (_value < 0 || _value > std::numeric_limits<float>::max() || _value > 2147483647.00)
				throw ValueError();
	}
	else
	{
		if (_value < 0)
			return (std::cout << "Error: not a positive number." << std::endl, 1);
		if (_value > 1000.00)
			return (std::cout << "Error: too large a number." << std::endl, 1);
	}
	return (0);
}

std::string	BitcoinExchange::trim(std::string& str)
{
	size_t	firstNonSpace = str.find_first_not_of(" \t\n\r\f\v");
	size_t	lastNonSpace = str.find_last_not_of(" \t\n\r\f\v");

	return (str.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1));
}

int	BitcoinExchange::CheckDate(void)
{
	std::string	day;
	std::string	month;
	std::string	year;

	std::istringstream	iss(_date);
	std::getline(iss, year, '-');
	if (CheckYear(year) == 1)
		return (1);
	std::getline(iss, month, '-');
	std::getline(iss, day);
	day = trim(day);
	if (CheckDay(day, month, year) == 1)
		return (1);
	return (0);
}

int	BitcoinExchange::CheckYear(std::string	year)
{
	if (year.length() != 4)
	{
		if (_bool == 0)
			throw YearError();
		else
			return (std::cout << "Error: Year error." << std::endl, 1);
	}
	int	yearr = atoi(year.c_str());
	if (yearr < 0 || yearr > 2024)
	{
		if (_bool == 0)
			throw YearError();
		else
			return (std::cout << "Error: Year error." << std::endl, 1);
	}
	return (0);
}

bool IsBisextile(int annee)
{
	return (annee % 4 == 0 && (annee % 100 != 0 || annee % 400 == 0));
}

int	BitcoinExchange::CheckDay(std::string	day, std::string	month, std::string	year) const
{
	if (day.length() != 2 || month.length() != 2)
	{
		if (_bool == 0)
			throw MonthError();
		else
			return (std::cout << "Error: Month error." << std::endl, 1);
	}
	int	monthh = atoi(month.c_str());
	int	dayy = atoi(day.c_str());
	switch (monthh)
	{
	case 1:
		if (dayy <= 0 || dayy > 31)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 2:
		if (dayy == 29)
		{
			if (!IsBisextile(atoi(year.c_str())))
				return (std::cout << "Error: Day error." << std::endl, 1);
			else
				break ;
		}
		if (dayy <= 0 || dayy > 28)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 3:
		if (dayy <= 0 || dayy > 31)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 4:
		if (dayy <= 0 || dayy > 30)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 5:
		if (dayy <= 0 || dayy > 31)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 6:
		if (dayy <= 0 || dayy > 30)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 7:
		if (dayy <= 0 || dayy > 31)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 8:
		if (dayy <= 0 || dayy > 31)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 9:
		if (dayy <= 0 || dayy > 30)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 10:
		if (dayy <= 0 || dayy > 31)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 11:
		if (dayy <= 0 || dayy > 30)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	case 12:
		if (dayy <= 0 || dayy > 31)
		{
			if (_bool == 0)
				throw DayError();
			else
				return (std::cout << "Error: Day error." << std::endl, 1);
		}
		break;
	default:
		if (_bool == 0)
			throw MonthError();
		else
			return (std::cout << "Error: Month error." << std::endl, 1);
	}
	return (0);
}

void	BitcoinExchange::printmap(void) const
{
	for (std::multimap<std::string, float>::const_iterator it = _DataMap.begin(); it != _DataMap.end(); ++it)
		std::cout << std::setprecision(2) << std::fixed << it->first << "," << it->second << std::endl;
}

const char*	BitcoinExchange::DayError::what(void) const throw()
{
	return ("Error Day in the bdd.\n");
};

const char*	BitcoinExchange::MonthError::what(void) const throw()
{
	return ("Error Month in the bdd.\n");
};

const char*	BitcoinExchange::YearError::what(void) const throw()
{
	return ("Error Year in the bdd.\n");
};

const char*	BitcoinExchange::ValueError::what(void) const throw()
{
	return ("Error Value in the bdd.\n");
};

const char*	BitcoinExchange::Emptybdd::what(void) const throw()
{
	return ("Error: BDD empty.\n");
};
