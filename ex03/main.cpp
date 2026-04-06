/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:13:26 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/03 18:16:26 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
    Point a(8,8);
    Point b(8,3);
    Point c(3,3);
    Point d(6.5f,5);
    if (bsp(a,b,c,d))
        std::cout << "Point d is inside the triangle abc" << std::endl;
    else
        std::cout << "Point d is outside the triangle abc" << std::endl;
    return 0;
}
