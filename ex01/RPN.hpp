#ifndef RPN_HPP
# define RPN_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <stdexcept>
# include <iomanip>
# include <iostream>
# include <limits>
# include <numbers>
# include <stack>
# include <cstdlib>

enum Operators {
    NONE,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

class RPN
{
    private:
        std::stack<int> _numbers;
        bool isNumber(const std::string &token);
        Operators isOperator(const std::string &token);
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        void calculate(const std::string &args);
};

#endif