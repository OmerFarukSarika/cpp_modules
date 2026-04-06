/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 03:43:58 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/29 17:06:15 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) ,_weapon(NULL)
{
    std::cout << "HumanB " << this->_name << " Created" << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->_name << " Destroyed" << std::endl;
}

void HumanB::attack(void)
{
    if (!_weapon)
        std::cout << this->_name << " has no weapon to attack with" << std::endl;
    else
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}

