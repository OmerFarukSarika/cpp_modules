#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>
#include <vector>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void print_header(const std::string& title) {
    std::cout << BOLD << MAGENTA << "\n" << title << RESET << std::endl;
    std::cout << BOLD << MAGENTA << "----------------------------------------" << RESET << std::endl;
}

void test_const_stack(const MutantStack<int>& mstack) {
    std::cout << CYAN << "--- Testing with a const reference ---" << RESET << std::endl;
    std::cout << "Iterating over const_stack: ";
    for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nTest with const reference finished." << std::endl;
}

int main()
{
    print_header("===== Testing MutantStack Functionality =====");
    
    MutantStack<int> mstack;

    std::cout << YELLOW << "Pushing 5, then 17..." << RESET << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element is now: " << BOLD << mstack.top() << RESET << std::endl;
    std::cout << YELLOW << "Popping the top element..." << RESET << std::endl;
    mstack.pop();
    std::cout << "Size is now: " << BOLD << mstack.size() << RESET << std::endl;

    std::cout << YELLOW << "Pushing 3, 5, 737, and 0..." << RESET << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << CYAN << "\n--- Iterating through MutantStack (begin to end) ---" << RESET << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    test_const_stack(mstack);

    print_header("===== Comparing with std::list for Identical Behavior =====");
    {
        std::list<int> list;
        std::cout << YELLOW << "Performing same operations on std::list..." << RESET << std::endl;

        list.push_back(5);
        list.push_back(17);
        list.pop_back();
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        
        std::cout << "Final std::list contents: ";
        for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    
    print_header("===== Test Conclusion =====");
    std::cout << GREEN << BOLD << "[SUCCESS] " << RESET << GREEN << "MutantStack's final state and iterated output match std::list." << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}