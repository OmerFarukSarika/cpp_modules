#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <climits>
#include <sstream>


enum literalType
    {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        PSEUDO,
        FALSE
    };

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        static void convert(const std::string &literal);
    };

literalType whatIsIt(const std::string &str);



#endif