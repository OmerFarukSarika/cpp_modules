/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:19:42 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/03 17:09:38 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        ~Point();
        Point(const Point &src);
        Point(const Fixed x, const Fixed y);
        Point &operator=(const Point &src);

        const Fixed getX(void) const;
        const Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif