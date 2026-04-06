/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:16:14 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/13 17:20:57 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
    _name = "DiamondTrap";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap name constructor called" << std::endl;
    this->_name = name;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = src;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    std::cout << "DiamondTrap assignation operator called" << std::endl;
    if (this != &src)
    {
        _name = src._name;
        hitPoints = src.hitPoints;
        energyPoints = src.energyPoints;
        attackDamage = src.attackDamage;
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::displayStats() const
{
    std::cout << std::endl << "=====STATS=====" << std::endl << std::endl;
    std::cout << "-> Diamond Name: " << _name << std::endl;
    std::cout << "-> Clap Name: " << ClapTrap::_name << std::endl;
    std::cout << "-> Hit Points: " << hitPoints << std::endl;
    std::cout << "-> Energy Points: " << energyPoints << std::endl;
    std::cout << "-> Attack Damage: " << attackDamage << std::endl << std::endl;
}
