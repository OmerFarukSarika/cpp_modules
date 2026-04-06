/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:46:37 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/09 17:23:12 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("ClapTrap"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    std::cout << "ClapTrap assigment constructor called" << std::endl;
    _name = copy._name;
    hitPoints = copy.hitPoints;
    energyPoints = copy.energyPoints;
    attackDamage = copy.attackDamage;
    return *this;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return attackDamage;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints == 0)
        std::cout << "ClapTrap " << _name << "out of energy!" << std::endl;
    else if (hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    else if (attackDamage == 0)
        std::cout << "ClapTrap " << _name << " has no attack damage!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
    else if (hitPoints <= amount)
    {
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
        hitPoints = 0;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " take " << amount << " points of damage!" << std::endl;
        hitPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints == 0)
        std::cout << "ClapTrap " << _name << " out of energy!" << std::endl;
    else if (hitPoints == 0)
        std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
    else
    {
        std::cout << "ClapTrap " << _name << " be repaired for " << amount << " points!" << std::endl;
        hitPoints += amount;
        energyPoints -= 1;
    }
}

void ClapTrap::displayStats() const
{
    std::cout << std::endl << "=====STATS=====" << std::endl << std::endl;
    std::cout << "-> Clap Name: " << _name << std::endl;
    std::cout << "-> Hit Points: " << hitPoints << std::endl;
    std::cout << "-> Energy Points: " << energyPoints << std::endl;
    std::cout << "-> Attack Damage: " << attackDamage << std::endl << std::endl;
}
