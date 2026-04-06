#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iterator>
#include <list>
#include <vector>
#include <iostream>
#include <cstdlib>

class Span
{
private:
    unsigned int N;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
    template <typename Iterator>
    void addRange(Iterator BeginIterator, Iterator EndIterator)
    {
        long IteratorSize = std::distance(BeginIterator, EndIterator);

        if (_numbers.size() + IteratorSize > N)
            throw SpanIsFull();
        _numbers.insert(_numbers.end(), BeginIterator, EndIterator);
        
    }
    class SpanIsFull : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "No space for a new number in the Span class";
        };
    };
    class SpanNumberCountError : public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Only 1 numbers in the Span class.";
        };
    };
};

#endif