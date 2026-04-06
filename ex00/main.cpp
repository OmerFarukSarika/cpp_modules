#include "ScalarConverter.hpp"
#include <errno.h>

int main(int argc, char **argv) {
    if (argc != 2){
        std::cout << "We need to 2 argument to execute this program" << std::endl;
        return -1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}