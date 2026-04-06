/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 03:38:43 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/24 03:40:56 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon(void)
{
    std::cout << "Weapon Destroyed" << std::endl;
}

const std::string &Weapon::getType(void)
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}