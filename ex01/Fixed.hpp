/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:49:39 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/31 21:56:43 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
};

std::ostream	&operator<< (std::ostream& out, const Fixed& fixed);

#endif