#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>

class Data {
    private:
        uintptr_t _value;
    public:
        Data();
        Data(uintptr_t value);
        Data(const Data &other);
        Data &operator=(const Data &other);
        ~Data();


        uintptr_t getValue() const;
        void setValue(uintptr_t value);
};

#endif