/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:51:35 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/03 17:10:34 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>

Fixed::Fixed() : value(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int value)
{
    this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->value = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

int Fixed::getRawBits(void) const
{
    return this->value;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
    return this->value >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &src) const
{
    return this->value > src.getRawBits();
}

bool Fixed::operator<(const Fixed &src) const
{
    return this->value < src.getRawBits();
}

bool Fixed::operator>=(const Fixed &src) const
{
    return this->value >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed &src) const
{
    return this->value <= src.getRawBits();
}

bool Fixed::operator==(const Fixed &src) const
{
    return this->value == src.getRawBits();
}

bool Fixed::operator!=(const Fixed &src) const
{
    return this->value != src.getRawBits();
}

Fixed Fixed::operator+(const Fixed &src) const
{
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator-(const Fixed &src) const
{
    return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator*(const Fixed &src) const
{
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator/(const Fixed &src) const
{
    return Fixed(this->toFloat() / src.toFloat());
}

Fixed &Fixed::operator++()
{
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--()
{
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return a > b ? a : b;
}