#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span &other) : N(other.N), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    N = other.N;
    _numbers = other._numbers;
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_numbers.size() < N)
        _numbers.push_back(number);
    else
        throw SpanIsFull();
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw SpanNumberCountError();
    long minSpan = __LONG_MAX__;
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    for (unsigned int i = 1; i < sorted.size(); i++)
    {
        if ((sorted[i] - sorted[i - 1]) < minSpan)
            minSpan = sorted[i] - sorted[i - 1];
    }
    return minSpan;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw SpanNumberCountError();
    std::vector<int>::iterator it = std::max_element(_numbers.begin(), _numbers.end());
    std::vector<int>::iterator it1 = std::min_element(_numbers.begin(), _numbers.end());
    int res = *it - *it1;
    return res;
}