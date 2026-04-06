#include "Data.hpp"

static void print(const std::string &text, int r, int g, int b)
{
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << text << "\033[0m" << std::endl;
}

Data::Data() : _value(0) {
    print("Data initialized", 0, 255, 0);
}

Data::Data(uintptr_t value) : _value(value) {
    print("Data initialized with value", 0, 255, 0);
}

Data::Data(const Data &other) : _value(other._value) {
    print("Data copy constructor called", 0, 255, 255);
}

Data &Data::operator=(const Data &other) {
    if (this != &other) {
        _value = other._value;
    }
    print("Data assignment operator called", 255, 255, 0);
    return *this;
}

Data::~Data() {
    print("Data destructor called", 255, 0, 0);
}

uintptr_t Data::getValue() const {
    return _value;
}

void Data::setValue(uintptr_t value) {
    _value = value;
}
