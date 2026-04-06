/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:48:40 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/09 17:30:39 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
 
int main()
{
    ClapTrap clapTrap("Ömer");
    std::cout << std::endl;
    ScavTrap scavTrap("Arif");

    std::cout << std::endl;
    clapTrap.attack("Arif");
    std::cout << std::endl;
    scavTrap.takeDamage(clapTrap.getAttackDamage());
    std::cout << std::endl;
    scavTrap.attack("Ömer");
    std::cout << std::endl;
    clapTrap.takeDamage(scavTrap.getAttackDamage());
    std::cout << std::endl;
    scavTrap.beRepaired(10);
    std::cout << std::endl;
    clapTrap.beRepaired(10);
    std::cout << std::endl;
    scavTrap.guardGate();
    std::cout << std::endl;
    return 0;
}