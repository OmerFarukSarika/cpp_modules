#include "ScalarConverter.hpp"

static bool isChar(const std::string &str)
{
    if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
        return true;
    return false;
}

static bool isInt(const std::string &str)
{
    if (str.length() == 1 && (str[0] == '+' || str[0] == '-'))
        return false;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (i == 0 && (str[i] == '+' || str[i] == '-'))
            continue;
        else if (!isdigit(str[i]))
            return false;
    }
    long long number = 0;
    int start = 0;
    bool negativeFlag = false;
    if (str[start] == '-' || str[start] == '+')
    {
        if (str[start] == '-')
            negativeFlag = true;
        start++;
    }
    for (size_t i = start; i < str.length(); ++i)
    {
        number = number * 10 + (str[i] - '0');
        if ((negativeFlag && (number > static_cast<long long>(INT_MAX) + 1)) || (!negativeFlag && number > INT_MAX))
            return false;
    }
    return true;
}

static bool isFloat(const std::string &str)
{
    if (str.empty() || str[str.length() - 1] != 'f' || (str[str.length() - 1] == 'f' && str[str.length() - 2] == '.'))
        return false;
    std::string numPart = str.substr(0, str.length() - 1);
    if (numPart.empty() || numPart == "." || numPart == "+" || numPart == "-" || numPart == "+." || numPart == "-.")
        return false;
    size_t i = 0;
    if (numPart[i] == '+' || numPart[i] == '-')
        i++;
    bool dotFound = false;
    for (; i < numPart.length(); ++i)
    {
        if (isdigit(numPart[i]))
            continue;
        else if (numPart[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else
            return false;
    }
    return true;
}

static bool isDouble(const std::string &str)
{
    if (str.empty())
        return false;
    std::string numPart = str.substr(0, str.length());
    if (numPart.empty() || numPart == "." || numPart == "+" || numPart == "-" || numPart == "+." || numPart == "-.")
        return false;
    size_t i = 0;
    if (numPart[i] == '+' || numPart[i] == '-')
        i++;
    bool dotFound = false;
    for (; i < numPart.length(); ++i)
    {
        if (isdigit(numPart[i]))
            continue;
        else if (numPart[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else
            return false;
    }
    return true;
}

static bool isPseudo(const std::string &str)
{
    if (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff" || str == "nanf" || str == "nan")
        return true;
    return false;
}

literalType whatIsIt(const std::string &str)
{
    if (isChar(str))
        return CHAR;
    if (isInt(str))
        return INT;
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;
    if (isPseudo(str))
        return PSEUDO;
    return FALSE;
}