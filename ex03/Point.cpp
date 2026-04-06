/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:19:36 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/03 18:08:30 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(0), y(0)
{
}

Point::~Point()
{
}

Point::Point(const Fixed x, const Fixed y) : x(x), y(y)
{
}

Point::Point(const Point &src) : x(src.x), y(src.y)
{
}

Point &Point::operator=(const Point &src)
{
    if (this != &src)
    {
        const_cast<Fixed &>(this->x) = src.x;
        const_cast<Fixed &>(this->y) = src.y;
    }
    return *this;
}

const Fixed Point::getX(void) const
{
    return this->x;
}

const Fixed Point::getY(void) const
{
    return this->y;
}