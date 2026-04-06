#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <iostream>
#include <cstdlib>

template <typename T>
typename T::iterator easyfind(T& container, int value);

# include "easyfind.tpp"

#endif