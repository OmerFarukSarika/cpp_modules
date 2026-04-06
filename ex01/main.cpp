#include <iostream>
#include "iter.hpp"

template<typename T>
void printElement(const T& element)
{
    std::cout << element << " ";
}

void increment(int& n)
{
    n++;
}

int main()
{    std::cout << "-----------------------------" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = 5;

    std::cout << "Original Int Array: ";
    iter(intArray, intArrayLength, printElement<int>);
    iter(intArray, intArrayLength, increment);
    std::cout << std::endl;

    std::cout << "After Increment: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl << "-----------------------------" << std::endl;

    std::string stringArray[] = {"Hello", "C++", "Templates"};
    size_t stringArrayLength = 3;

    std::cout << "String Array: ";
    iter(stringArray, stringArrayLength, printElement<std::string>);
    std::cout << std::endl << "-----------------------------" << std::endl;

    const int constIntArray[] = {10, 20, 30};
    size_t constIntArrayLength = 3;

    std::cout << "Const Int Array: ";
    iter(constIntArray, constIntArrayLength, printElement<int>);
    std::cout << std::endl << "-----------------------------" << std::endl;
    return 0;
}