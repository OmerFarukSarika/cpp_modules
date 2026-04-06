#include "Serializer.hpp"

static void print(const std::string &text, int r, int g, int b)
{
    std::cout << "\033[38;2;" << r << ";" << g << ";" << b << "m" << text << "\033[0m" << std::endl;
}

Serializer::Serializer() {
    print("Serializer initialized", 0, 255, 0);
}

Serializer::Serializer(const Serializer &other) {
    (void)other;
    print("Serializer copy constructor called", 0, 255, 255);
}

Serializer &Serializer::operator=(const Serializer &other) {
    (void)other;
    if (this != &other) {
        ;
    }
    print("Serializer assignment operator called", 255, 255, 0);
    return *this;
}

Serializer::~Serializer() {
    print("Serializer destructor called", 255, 0, 0);
}

uintptr_t Serializer::serialize(Data *ptr) {
    print("Serializing Data", 0, 128, 255);
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    print("Deserializing Data", 128, 0, 255);
    return reinterpret_cast<Data*>(raw);
}

