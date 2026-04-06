/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 03:35:46 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/24 03:43:39 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
    std::cout << "HumanA " << this->_name << " Created" << std::endl;
}

HumanA::~HumanA(void)
{
    std::cout << "HumanA " << this->_name << " Destroyed" << std::endl;
}

void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}