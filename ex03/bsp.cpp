/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:23:31 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/03 18:20:30 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Fixed abs(Fixed const &n)
{
    if (n < 0)
        return (n * -1);
    return n;
}

void tri_area_calc(Fixed &triangle, Point a, Point b, Point c)
{
    triangle = (Fixed(0.5f) * abs(a.getX() * (b.getY() - c.getY()) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed triangle_area(0);
    Fixed triangle_area1(0);
    Fixed triangle_area2(0);
    Fixed triangle_area3(0);

    tri_area_calc(triangle_area, a, b, c);
    tri_area_calc(triangle_area1, a, b, point);
    tri_area_calc(triangle_area2, b, c, point);
    tri_area_calc(triangle_area3, c, a, point);
    if (triangle_area == 0 || triangle_area1 == 0 || triangle_area2 == 0 || triangle_area3 == 0)
        return false;
    else if (triangle_area == triangle_area1 + triangle_area2 + triangle_area3)
        return true;
    return false;
}
