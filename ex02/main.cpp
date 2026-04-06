/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:48:40 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/10 16:00:25 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
    FragTrap fragtrap("Atalay");
    std::cout << std::endl;
    ScavTrap scavtrap("Onur");
    std::cout << std::endl;

    scavtrap.attack("Atalay");
    std::cout << std::endl;
    scavtrap.guardGate();
    std::cout << std::endl;
    fragtrap.highFivesGuys();
    std::cout << std::endl;
    fragtrap.attack("Onur");
    std::cout << std::endl;
    fragtrap.takeDamage(scavtrap.getAttackDamage());
    std::cout << std::endl;
    fragtrap.beRepaired(20);
    std::cout << std::endl;
    scavtrap.takeDamage(fragtrap.getAttackDamage());
    std::cout << std::endl;
    scavtrap.beRepaired(20);
    fragtrap.displayStats();
    scavtrap.displayStats();
    return 0;
}