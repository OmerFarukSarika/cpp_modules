#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numbers>

enum	ERROR
{
    SUCCESS,
	NEGATİVE,
    LARGE,
    BAD_İNPUT,
    WRONG_ARG,
    BAD_DATE_FORMAT,
    INVALID_MONTH,
    INVALID_DAY
};

class BitcoinExchange
{
  private:
	std::map<std::string, float> database;

  public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);

	void loadData(const std::string &filename);
	void DatabaseCheck(const std::string &filename);
	void trim(std::string &str);
	ERROR isValidDate(const std::string &date);
	bool isLeapYear(const int &year, const int &month, const int &day);
	ERROR isValidValue(const std::string &value);
    void  WhichError(ERROR error_num, const std::string &error_str);


	class NegativeNumber : public std::exception
	{
		public:
            virtual const char *what() const throw()
            {
                return ("Error: not a positive number.");
            }
	};
    class LargeNumber : public std::exception
	{
		public:
            virtual const char *what() const throw()
            {
                return ("Error: too large a number.");
            }
	};
    class WrongArgument : public std::exception
	{
		public:
            virtual const char *what() const throw()
            {
                return ("Error: could not open file.");
            }
	};
    class WrongDay : public std::exception
	{
        private:
            std::string _message;
		public:
            WrongDay(const std::string& date_str)
            {
                _message = "Error: An invalid day => " + date_str;
            }
            virtual ~WrongDay() throw() {}
            virtual const char *what() const throw()
            {
                return _message.c_str();
            }
	};
    class WrongMonth : public std::exception
	{
        private:
            std::string _message;
		public:
            WrongMonth(const std::string& date_str)
            {
                _message = "Error: An invalid month => " + date_str;
            }
            virtual ~WrongMonth() throw() {}
            virtual const char *what() const throw()
            {
                return _message.c_str();
            }
	};
    class BadDateFormat : public std::exception
	{
        private:
            std::string _message;
		public:
            BadDateFormat(const std::string& date_str)
            {
                _message = "Error: Bad date format => " + date_str;
            }
            virtual ~BadDateFormat() throw() {}
            virtual const char *what() const throw()
            {
                return _message.c_str();
            }
	};
    class BadInput : public std::exception
	{
        private:
            std::string _message;
		public:
            BadInput(const std::string& date_str)
            {
                _message = "Error: Bad input format => " + date_str;
            }
            virtual ~BadInput() throw() {}
            virtual const char *what() const throw()
            {
                return _message.c_str();
            }
	};
};

#endif