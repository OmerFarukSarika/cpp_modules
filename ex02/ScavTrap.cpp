/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:00:07 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/10 15:58:32 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = copy;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
    std::cout << "ScavTrap name constructor called" << std::endl;
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap assigment constructor called" << std::endl;
    _name = copy._name;
    hitPoints = copy.hitPoints;
    energyPoints = copy.energyPoints;
    attackDamage = copy.attackDamage;
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (energyPoints == 0)
        std::cout << "ScavTrap " << _name << "out of energy!" << std::endl;
    else if (hitPoints == 0)
        std::cout << "ScavTrap " << _name << " is dead!" << std::endl;
    else if (attackDamage == 0)
        std::cout << "ScavTrap " << _name << " has no attack damage!" << std::endl;
    else
    {
        std::cout << "ScavTrap " << _name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints -= 1;
    }
}