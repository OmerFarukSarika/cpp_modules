#include "PmergeMe.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Please enter a sequence number to sort by." << std::endl;
		return (1);
	}
	std::vector<int> numbers_vec;
	for (int i = 1; i < argc; ++i)
	{
		
		char *endptr;
		long value = std::strtol(argv[i], &endptr, 10);
		if (*endptr != '\0' || argv[i] == endptr || value <= 0 || value > INT_MAX)
		{
			std::cerr << "Hata: Invalid input => \"" << argv[i] << "\"" << std::endl;
			return (1);
		}
		numbers_vec.push_back(static_cast<int>(value));
	}
	std::cout << "Before: ";
	for (size_t i = 0; i < numbers_vec.size(); ++i)
	{
		std::cout << numbers_vec[i] << " ";
	}
	std::cout << std::endl;

	PmergeMe sorter;
	sorter.sortAndPrint(numbers_vec);

	return (0);
}