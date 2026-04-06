/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:39 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/03 17:11:28 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <math.h>

class Fixed
{
    private:
        int value;
        static const int fractionalBits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &src);
        Fixed &operator=(const Fixed &src);
        float toFloat(void) const;
        int toInt(void) const;
        void setRawBits(int const raw);
        int getRawBits(void) const;
        bool operator>(const Fixed &src) const;
        bool operator<(const Fixed &src) const;
        bool operator>=(const Fixed &src) const;
        bool operator<=(const Fixed &src) const;
        bool operator==(const Fixed &src) const;
        bool operator!=(const Fixed &src) const;
        Fixed operator+(const Fixed &src) const;
        Fixed operator-(const Fixed &src) const;
        Fixed operator*(const Fixed &src) const;
        Fixed operator/(const Fixed &src) const;
        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<< (std::ostream& out, const Fixed& fixed);

#endif