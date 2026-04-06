#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>
# include <string>
# include <sys/time.h>
# include <utility>
# include <vector>

class PmergeMe
{
  public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void sortAndPrint(const std::vector<int> &input);

  private:
	std::vector<int> _main_sort_vec(std::vector<int> vec);

	std::list<int> _main_sort_list(std::list<int> lst);

	std::vector<int> _generate_insertion_sequence(int num_pendants);
};

#endif