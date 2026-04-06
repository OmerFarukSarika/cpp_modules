#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc;
    
    try
    {
        if (ac != 2){
            btc.WhichError(WRONG_ARG, "");
        }
        btc.loadData("data.csv");
        btc.DatabaseCheck(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}