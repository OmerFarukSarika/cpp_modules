#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		database = other.database;
	}
	return (*this);
}

bool	split(const std::string &str, char limiter, std::string &date_part,
		std::string &value_part)
{
	std::stringstream ss(str);
	if (std::getline(ss, date_part, limiter))
		if (std::getline(ss, value_part))
			return (true);
	return (false);
}

void BitcoinExchange::WhichError(ERROR error_num, const std::string &error_str)
{
	if (error_num == NEGATİVE)
		throw NegativeNumber();
	if (error_num == LARGE)
		throw LargeNumber();
	if (error_num == WRONG_ARG)
		throw WrongArgument();
	if (error_num == BAD_DATE_FORMAT)
		throw BadDateFormat(error_str);
	if (error_num == INVALID_DAY)
		throw WrongDay(error_str);
	if (error_num == INVALID_MONTH)
		throw WrongMonth(error_str);
	if (error_num == BAD_İNPUT)
		throw BadInput(error_str);
}

void BitcoinExchange::loadData(const std::string &filename)
{
	float price;
	std::string date_part;
	std::string value_part;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Could not open file: " + filename);
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (split(line, ',', date_part, value_part))
		{
			trim(date_part);
			trim(value_part);
			WhichError(isValidDate(date_part), date_part);
			std::stringstream ss_value(value_part);
			ss_value >> price;
			if (ss_value.fail())
				throw std::runtime_error("Error: value is not a valid number.");
			database[date_part] = price;
		}
	}
}

void BitcoinExchange::DatabaseCheck(const std::string &filename)
{
			float price;
	float	exchange_rate;

	std::string date_part;
	std::string value_part;
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file: " + filename);
	}
	std::string line;
	try
	{
		getline(file, line);
		trim(line);
		if (line != "date | value")
			WhichError(BAD_İNPUT, line);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	while (getline(file, line))
	{
		split(line, '|', date_part, value_part);
		trim(date_part);
		trim(value_part);
		try
		{
			WhichError(isValidDate(date_part), date_part);
			WhichError(isValidValue(value_part), value_part);
			std::stringstream ss_value(value_part);
			ss_value >> price;
			if (ss_value.fail())
				throw std::runtime_error("Error: value is not a valid number.");
			std::map<std::string,float>::iterator it = database.lower_bound(date_part);
			if (it == database.end() || it->first != date_part)
			{
				if (it == database.begin())
				{
					throw std::runtime_error("Error: No data available before " + date_part);
				}
				it--;
			}
			exchange_rate = it->second;
			std::cout << std::fixed << std::setprecision(2);;
            std::cout << date_part << " => " << value_part << " = " << price * exchange_rate << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

bool BitcoinExchange::isLeapYear(const int &year, const int &month,
	const int &day)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		if (month == 2 && day > 29)
			return (false);
	}
	else if (month == 2 && day > 28)
		return (false);
	return (true);
}
ERROR BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return BAD_DATE_FORMAT;
    std::stringstream ss(date);
    int year, month, day;
    char seperator1, seperator2;

    if (!(ss >> year >> seperator1 >> month >> seperator2 >> day) || !ss.eof())
        return BAD_DATE_FORMAT;
    if (seperator1 != '-' || seperator2 != '-')
        return BAD_DATE_FORMAT;    
    if (month < 1 || month > 12)
        return INVALID_MONTH;
    if (day < 1 || day > 31)
        return INVALID_DAY;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return INVALID_DAY;
    if (!isLeapYear(year, month, day))
		return INVALID_DAY;

    return SUCCESS;
}

ERROR BitcoinExchange::isValidValue(const std::string &value)
{
	double	_value;

	std::stringstream ss(value);
	ss >> _value;
	if (ss.fail() || _value < 0 || _value > 1000)
	{
		if (_value < 0)
			return NEGATİVE;
		else if (_value > 1000)
			return LARGE;
	}	
	return (SUCCESS);
}

void BitcoinExchange::trim(std::string &str)
{
	size_t first = str.find_first_not_of(" \t");
	size_t last = str.find_last_not_of(" \t");

	if (first == std::string::npos || last == std::string::npos)
		str = "";
	else
		str = str.substr(first, last - first + 1);
}