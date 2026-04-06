#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _numbers = other._numbers;
    }
    return (*this);
}

bool RPN::isNumber(const std::string &token)
{
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (token[i] < '0' || token[i] > '9')
			return (false);
	}
	return (true);
}

Operators RPN::isOperator(const std::string &token)
{
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (token[i] == '+')
			return (ADD);
		else if (token[i] == '*')
			return (MULTIPLY);
		else if (token[i] == '-')
			return (SUBTRACT);
		else if (token[i] == '/')
			return (DIVIDE);
	}
	return (NONE);
}

void RPN::calculate(const std::string &args)
{
	Operators	op;
	int			num;
	int			right;
	int			left;
	int         result;

	std::stringstream ss(args);
	std::string token;
	while (ss >> token && !ss.fail())
	{
		if (isNumber(token))
        {
            std::stringstream ss_num(token);
            ss_num >> num;
            if (num > 9 || num < 0) {
                throw std::runtime_error("Error");
            } 
            _numbers.push(num);
        }
		else
		{
			op = isOperator(token);
			if (op != NONE)
			{
				if (_numbers.size() < 2)
                	throw std::runtime_error("Error");
				right = _numbers.top();
				_numbers.pop();
				left = _numbers.top();
				_numbers.pop();
				switch (op)
                    {
                        case ADD:
                            result = left + right;
                            break ;
                        case SUBTRACT:
                            result = left - right;
                            break ;
                        case MULTIPLY:
                            result = left * right;
                            break ;
                        case DIVIDE:
                            if (right == 0)
                				throw std::runtime_error("Error");
                            result = left / right;
                            break ;
                        default:
                            break ;
                    }
				_numbers.push(result);
			}
			else
                throw std::runtime_error("Error");
		}
	}
    if (_numbers.size() != 1) {
        std::cerr << "Error" << std::endl;
    } else {
        std::cout << _numbers.top() << std::endl;
    }
}