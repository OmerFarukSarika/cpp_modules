#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <algorithm>
# include <deque>
# include <iostream>
# include <list>
# include <stack>
# include <vector>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
	    ~MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack& operator=(const MutantStack &other);

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();

        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        const_iterator begin() const;
        const_iterator end() const;
};

# include "MutantStack.tpp"

#endif