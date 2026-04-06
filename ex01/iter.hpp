#ifndef iter_hpp
# define iter_hpp

#include <iostream>

template <typename T>
void iter(T* address, size_t length, void (*func)(T&))
{
    for (size_t i = 0; i < length; i++)
    {
        func(address[i]);
    }
}

template<typename T>
void iter(const T* address, size_t length, void (*func)(const T&))
{
    for (size_t i = 0; i < length; i++)
    {
        func(address[i]);
    }
}
#endif