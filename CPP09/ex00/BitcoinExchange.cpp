#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream& file): _file(file)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& substitue): _file(substitue._file)
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

void	BitcoinExchange::PutDataInMap(void)
{
	std::string	line;
	while (std::getline(_file, line))
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
				_DataMap[_date] = _value;
			}
		}
	}
}


void	BitcoinExchange::CheckValue(void) const
{
	if (_value < 0 || _value > std::numeric_limits<float>::max())
		throw ValueError();
}

void	BitcoinExchange::CheckDate(void) const
{
	std::string	day;
	std::string	month;
	std::string	year;

	std::istringstream	iss(_date);
	std::getline(iss, year, '-');
	CheckYear(year);
	std::getline(iss, month, '-');
	std::getline(iss, day);
	CheckDay(day, month);
}

void	BitcoinExchange::CheckYear(std::string	year) const
{
	if (year.length() != 4)
		throw YearError();
	int	yearr = atoi(year.c_str());
	if (yearr < 0 || yearr > 9999)
		throw YearError();
}

void	BitcoinExchange::CheckDay(std::string	day, std::string	month) const
{
	if (day.length() != 2 || month.length() != 2)
		throw MonthError();
	int	monthh = atoi(month.c_str());
	int	dayy = atoi(day.c_str());
	switch (monthh)
	{
	case 1:
		if (dayy < 0 || dayy > 31)
			throw DayError();
		break;
	case 2:
		if (dayy < 0 || dayy > 28)
			throw DayError();
		break;
	case 3:
		if (dayy < 0 || dayy > 31)
			throw DayError();
		break;
	case 4:
		if (dayy < 0 || dayy > 30)
			throw DayError();
		break;
	case 5:
		if (dayy < 0 || dayy > 31)
			throw DayError();
		break;
	case 6:
		if (dayy < 0 || dayy > 30)
			throw DayError();
		break;
	case 7:
		if (dayy < 0 || dayy > 31)
			throw DayError();
		break;
	case 8:
		if (dayy < 0 || dayy > 31)
			throw DayError();
		break;
	case 9:
		if (dayy < 0 || dayy > 30)
			throw DayError();
		break;
	case 10:
		if (dayy < 0 || dayy > 31)
			throw DayError();
		break;
	case 11:
		if (dayy < 0 || dayy > 30)
			throw DayError();
		break;
	case 12:
		if (dayy < 0 || dayy > 31)
			throw DayError();
		break;
	default:
		throw MonthError();
	}
}

void	BitcoinExchange::printmap(void) const
{
	for (std::map<std::string, float>::const_iterator it = _DataMap.begin(); it != _DataMap.end(); ++it)
		std::cout << std::setprecision(2) << std::fixed << it->first << "," << it->second << std::endl;
}

const char*	BitcoinExchange::DayError::what(void) const throw()
{
	return ("Error Day\n");
};

const char*	BitcoinExchange::MonthError::what(void) const throw()
{
	return ("Error Month\n");
};

const char*	BitcoinExchange::YearError::what(void) const throw()
{
	return ("Error Year\n");
};

const char*	BitcoinExchange::ValueError::what(void) const throw()
{
	return ("Error Value\n");
};