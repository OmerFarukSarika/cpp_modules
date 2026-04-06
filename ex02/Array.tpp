#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {
    std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {
    std::cout << "Parameterized constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array(){
    delete[] _array;
    std::cout << "Destructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(new T[other.size()]), _size(other.size())
{
    for (unsigned int i = 0; i < _size; ++i)
        _array[i] = other._array[i];
    std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other) {
    if (this != &other)
    {
        if (_array != NULL)
            delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    std::cout << "Assignment operator called" << std::endl;
    return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (_size);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw Array<T>::IndexOutOfRange();
    return (_array[i]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw Array<T>::IndexOutOfRange();
    return (_array[i]);
}
