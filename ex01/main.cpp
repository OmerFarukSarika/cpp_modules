#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

void print_header(const std::string& title) {
    std::cout << BOLD << MAGENTA << "\n--- " << title << " ---" << RESET << std::endl;
}

void print_result(const std::string& test_name, bool success) {
    if (success) {
        std::cout << GREEN << BOLD << "  [SUCCESS] " << RESET << GREEN << test_name << RESET << std::endl;
    } else {
        std::cout << RED << BOLD << "  [FAIL]    " << RESET << RED << test_name << RESET << std::endl;
    }
}

int main() {
    srand(time(NULL));

    print_header("Simple Test: PDF Example");
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Numbers: 6, 3, 17, 9, 11" << std::endl;
        print_result("shortestSpan() should be 2", sp.shortestSpan() == 2);
        print_result("longestSpan() should be 14", sp.longestSpan() == 14);
    }

    print_header("Exception Tests");
    {
        bool full_test_passed = false;
        try {
            Span sp(2);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
        } catch (const std::exception& e) {
            full_test_passed = true;
            std::cout << CYAN << "  (Expected exception caught: " << e.what() << ")" << RESET << std::endl;
        }
        print_result("Exception should be thrown when Span is full", full_test_passed);

        bool not_enough_test_passed = false;
        try {
            Span sp(5);
            sp.addNumber(42);
            sp.shortestSpan();
        } catch (const std::exception& e) {
            not_enough_test_passed = true;
            std::cout << CYAN << "  (Expected exception caught: " << e.what() << ")" << RESET << std::endl;
        }
        print_result("Span calculation with insufficient numbers should throw", not_enough_test_passed);
    }

    print_header("Large-Scale Test (15,000 Elements)");
    {
        try {
            const int size = 15000;
            std::vector<int> vec;
            vec.reserve(size);
            for (int i = 0; i < size; ++i) {
                vec.push_back(rand());
            }

            Span sp(size);
            sp.addRange(vec.begin(), vec.end());

            std::cout << "  15,000 elements added successfully." << std::endl;
            std::cout << "  Longest span: " << sp.longestSpan() << std::endl;
            std::cout << "  Shortest span: " << sp.shortestSpan() << std::endl;
            print_result("Large-scale test completed successfully", true);
        } catch (const std::exception& e) {
            print_result("Error during large-scale test", false);
            std::cerr << "  Error: " << e.what() << '\n';
        }
    }

    print_header("Copy & Assignment Operator Test");
    {
        Span original(10);
        original.addNumber(100);
        original.addNumber(200);

        Span copy = original;
        
        Span assigned(5);
        assigned = original;

        std::cout << "Original span's longestSpan value: " << original.longestSpan() << std::endl;
        print_result("Copied span should contain the correct value", copy.longestSpan() == original.longestSpan());
        print_result("Assigned span should contain the correct value", assigned.longestSpan() == original.longestSpan());
    }

    std::cout << BOLD << MAGENTA << "\n===== All Span Tests Completed =====\n" << RESET << std::endl;
    return 0;
}