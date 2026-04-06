#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array &other);
        Array &operator=(const Array &other);

        unsigned int size() const;
    
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        class IndexOutOfRange : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return "Error: Index is out of range.";
                }
        };
};

# include "Array.tpp"

#endif