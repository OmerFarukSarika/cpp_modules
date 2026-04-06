#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
	}
	return (*this);
}
PmergeMe::~PmergeMe()
{
}

void PmergeMe::sortAndPrint(const std::vector<int> &input)
{
	long	sec_vec;
	long	usec_vec;
	double	time_vec;
	long	sec_list;
	long	usec_list;
	double	time_list;

	timeval start_vec, end_vec;
	gettimeofday(&start_vec, NULL);
	std::vector<int> sorted_vec = _main_sort_vec(input);
	gettimeofday(&end_vec, NULL);
	sec_vec = end_vec.tv_sec - start_vec.tv_sec;
	usec_vec = end_vec.tv_usec - start_vec.tv_usec;
	time_vec = sec_vec * 1e6 + usec_vec;
	std::list<int> input_list(input.begin(), input.end());
	timeval start_list, end_list;
	gettimeofday(&start_list, NULL);
	std::list<int> sorted_list = _main_sort_list(input_list);
	gettimeofday(&end_list, NULL);
	sec_list = end_list.tv_sec - start_list.tv_sec;
	usec_list = end_list.tv_usec - start_list.tv_usec;
	time_list = sec_list * 1e6 + usec_list;
	std::cout << "After:  ";
	for (std::vector<int>::iterator it = sorted_vec.begin(); it != sorted_vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << input.size() << " elements with std::list   : " << time_list << " us" << std::endl;
}

std::vector<int> PmergeMe::_generate_insertion_sequence(int num_pendants)
{
	int	prev_jacobsthal;
	int	current_jacobsthal;
	int	next_jacobsthal;
	int	temp;

	std::vector<int> sequence;
	prev_jacobsthal = 1;
	current_jacobsthal = 1;
	while (current_jacobsthal < num_pendants)
	{
		next_jacobsthal = current_jacobsthal + 2 * prev_jacobsthal;
		for (int i = std::min(next_jacobsthal, num_pendants); i > current_jacobsthal; --i)
		{
			sequence.push_back(i);
		}
		temp = current_jacobsthal;
		current_jacobsthal = next_jacobsthal;
		prev_jacobsthal = temp;
	}
	return (sequence);
}

std::vector<int> PmergeMe::_main_sort_vec(std::vector<int> vec)
{
	int	straggler;
	int	pend_index;
	int	value_to_insert;

	if (vec.size() <= 1)
		return (vec);
	std::vector<std::pair<int, int> > pairs;
	straggler = -1;
	for (size_t i = 0; i < vec.size() / 2; ++i)
		pairs.push_back(std::make_pair(vec[i * 2], vec[i * 2 + 1]));
	if (vec.size() % 2 != 0)
		straggler = vec.back();
	for (size_t i = 0; i < pairs.size(); ++i)
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	std::vector<int> main_chain;
	for (size_t i = 0; i < pairs.size(); ++i)
		main_chain.push_back(pairs[i].first);
	std::vector<int> sorted_main_chain = _main_sort_vec(main_chain);
	std::vector<std::pair<int, int> > sorted_pairs;
	for (size_t i = 0; i < sorted_main_chain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (sorted_main_chain[i] == pairs[j].first)
			{
				sorted_pairs.push_back(pairs[j]);
				break ;
			}
		}
	}
	std::vector<int> pendants;
	for (size_t i = 0; i < sorted_pairs.size(); ++i)
		pendants.push_back(sorted_pairs[i].second);
	std::vector<int> result;
	result.push_back(pendants[0]);
	result.insert(result.end(), sorted_main_chain.begin(),
		sorted_main_chain.end());
	std::vector<int> insertion_sequence = _generate_insertion_sequence(pendants.size());
	for (size_t i = 0; i < insertion_sequence.size(); ++i)
	{
		pend_index = insertion_sequence[i] - 1;
		value_to_insert = pendants[pend_index];
		std::vector<int>::iterator it = std::lower_bound(result.begin(),
				result.end(), value_to_insert);
		result.insert(it, value_to_insert);
	}
	if (straggler != -1)
	{
		std::vector<int>::iterator it = std::lower_bound(result.begin(),
				result.end(), straggler);
		result.insert(it, straggler);
	}
	return (result);
}

std::list<int> PmergeMe::_main_sort_list(std::list<int> lst)
{
	if (lst.size() <= 1)
		return (lst);

	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;
	std::list<int>::iterator it = lst.begin();
	while (it != lst.end())
	{
		int val1 = *it++;
		if (it != lst.end())
		{
			int val2 = *it++;
			pairs.push_back(std::make_pair(val1, val2));
		}
		else
			straggler = val1;
	}
	for (size_t i = 0; i < pairs.size(); ++i)
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);

	std::list<int> main_chain;
	for (size_t i = 0; i < pairs.size(); ++i)
		main_chain.push_back(pairs[i].first);

	std::list<int> sorted_main_chain = _main_sort_list(main_chain);
	std::vector<std::pair<int, int> > sorted_pairs;
	for (std::list<int>::iterator sorted_it = sorted_main_chain.begin(); sorted_it != sorted_main_chain.end(); ++sorted_it)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (*sorted_it == pairs[j].first)
			{
				sorted_pairs.push_back(pairs[j]);
				break ;
			}
		}
	}

	std::vector<int> pendants;
	for (size_t i = 0; i < sorted_pairs.size(); ++i)
		pendants.push_back(sorted_pairs[i].second);

	std::list<int> result;
	result.push_back(pendants[0]);
	result.insert(result.end(), sorted_main_chain.begin(),
		sorted_main_chain.end());

	std::vector<int> insertion_sequence = _generate_insertion_sequence(pendants.size());

	for (size_t i = 0; i < insertion_sequence.size(); ++i)
	{
		int pend_index = insertion_sequence[i] - 1;
		int value_to_insert = pendants[pend_index];
		std::list<int>::iterator it_pos = std::lower_bound(result.begin(), result.end(), value_to_insert);
		result.insert(it_pos, value_to_insert);
	}

	if (straggler != -1)
	{
		std::list<int>::iterator it_pos = std::lower_bound(result.begin(),
				result.end(), straggler);
		result.insert(it_pos, straggler);
	}
	return (result);
}