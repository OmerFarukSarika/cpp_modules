/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:48:40 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/06 13:40:35 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
 
int main()
{
    ClapTrap clapTrap("Ömer");

    clapTrap.attack("Arif");
    clapTrap.takeDamage(9);
    clapTrap.beRepaired(12);
    return 0;
}