#include "ScalarConverter.hpp"

static void print(const std::string &text, int r, int g, int b)
{
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << text << "\033[0m" << std::endl;
}

ScalarConverter::ScalarConverter()
{
    print("ScalarConverter initialized", 0, 255, 0);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
    print("ScalarConverter copy constructor called", 0, 255, 255);
}

ScalarConverter::~ScalarConverter()
{
    print("ScalarConverter destructor called", 255, 0, 0);
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    if (this != &other)
        ;
    print("ScalarConverter assignment operator called", 255, 255, 0);
    return *this;
}

void ScalarConverter::convert(const std::string &literal)
{
    literalType type = whatIsIt(literal);

    if (type == CHAR)
    {
        char character = literal[0];
        std::cout << "char: '" << character << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(character) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(character) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(character) << std::endl;
    }
    else if (type == INT)
    {
        std::stringstream ss(literal);
        int intCharacter;

        ss >> intCharacter;
        if (ss.fail() || !ss.eof())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        if (intCharacter >= CHAR_MIN && intCharacter <= CHAR_MAX)
        {
            if (isprint(static_cast<char>(intCharacter)))
                std::cout << "char: '" << static_cast<char>(intCharacter) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;
        std::cout << "int: " << intCharacter << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(intCharacter) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(intCharacter) << std::endl;
    }
    else if (type == FLOAT)
    {
        std::string numPart = literal.substr(0, literal.length() - 1);
        std::stringstream ss(numPart);
        float floatValue;

        ss >> floatValue;
        if (ss.fail() || !ss.eof())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        if (floatValue >= CHAR_MIN && floatValue <= CHAR_MAX)
        {
            if (isprint(static_cast<char>(floatValue)))
                std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;
        if (floatValue >= static_cast<double>(INT_MIN) && floatValue <= static_cast<double>(INT_MAX))
            std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(floatValue) << std::endl;
    }
    else if (type == DOUBLE)
    {
        std::stringstream ss(literal);
        double doubleCharacter;

        ss >> doubleCharacter;
        if (ss.fail() || !ss.eof())
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        if (doubleCharacter >= CHAR_MIN && doubleCharacter <= CHAR_MAX)
        {
            if (isprint(static_cast<char>(doubleCharacter)))
                std::cout << "char: '" << static_cast<char>(doubleCharacter) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;
        if (doubleCharacter >= INT_MIN && doubleCharacter <= INT_MAX)
            std::cout << "int: " << static_cast<int>(doubleCharacter) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        if (doubleCharacter > std::numeric_limits<float>::max())
            std::cout << "float: +inff" << std::endl;
        else if (doubleCharacter < -std::numeric_limits<float>::max())
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(doubleCharacter) << "f" << std::endl;
        std::cout << "double: " << doubleCharacter << std::endl;
    }
    else if (type == PSEUDO)
    {
        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else if (literal == "+inf" || literal == "+inff")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
    }
    else if (type == FALSE)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}
