#include "easyfind.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"

template <typename T>
void run_test_suite(T &container, const std::string &containerName, int value_to_find, int value_not_to_find)
{
    std::cout << BOLD << MAGENTA << "\n===== Running Tests for " << containerName << " ===== " << RESET << std::endl;
    std::cout << BLUE << "Container contents: " << RESET;
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << YELLOW << "Test 1: Searching for an existing value (" << value_to_find << ")..." << RESET << std::endl;
    try
    {
        typename T::iterator it = easyfind(container, value_to_find);
        std::cout << GREEN << BOLD << "  [SUCCESS] " << RESET << GREEN << "Value found: " << *it << RESET << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << BOLD << "  [FAIL] " << RESET << RED << "Value should have been found, but an exception was thrown: " << e.what() << RESET << '\n';
    }
    std::cout << YELLOW << "Test 2: Searching for a non-existing value (" << value_not_to_find << ")..." << RESET << std::endl;
    try
    {
        easyfind(container, value_not_to_find);
        std::cerr << RED << BOLD << "  [FAIL] " << RESET << RED << "An exception was expected but not thrown." << RESET << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << GREEN << BOLD << "  [SUCCESS] " << RESET << GREEN << "Correctly caught expected exception: " << e.what() << RESET << '\n';
    }
}

int main(void)
{
    srand(time(NULL));

    std::vector<int> my_vector;
    for (int i = 0; i < 10; i++)
    {
        my_vector.push_back(rand() % 100);
    }
    my_vector.push_back(42);

    std::list<int> my_list;
    for (int i = 0; i < 10; i++)
    {
        my_list.push_back(rand() % 100);
    }
    my_list.push_back(84);

    run_test_suite(my_vector, "std::vector<int>", 42, 101);
    run_test_suite(my_list, "std::list<int>", 84, 101);

    std::cout << BOLD << MAGENTA << "\n===== Special Test on Empty std::vector<int> =====" << RESET << std::endl;
    std::vector<int> empty_vector;
    std::cout << BLUE << "Container contents: (empty)" << RESET << std::endl;
    std::cout << YELLOW << "Test: Searching for a value in empty container (42)..." << RESET << std::endl;
    try
    {
        easyfind(empty_vector, 42);
        std::cerr << RED << BOLD << "  [FAIL] " << RESET << RED << "Exception was expected for empty container but not thrown." << RESET << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << GREEN << BOLD << "  [SUCCESS] " << RESET << GREEN << "Correctly caught expected exception for empty container: " << e.what() << RESET << '\n';
    }

    std::cout << BOLD << MAGENTA << "\n===== All Tests Completed =====\n" << RESET << std::endl;
    return (0);
}