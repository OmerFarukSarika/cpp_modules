/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:24:05 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/31 20:44:03 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int value;
    static const int bits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &src);
    Fixed &operator=(const Fixed &src);

    void setRawBits(int const raw);
    int getRawBits(void) const;
};

#endif