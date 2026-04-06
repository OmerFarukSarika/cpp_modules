/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:19 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/09 17:10:00 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        virtual ~ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap(std::string const &name);
        ScavTrap &operator=(const ScavTrap &copy);
        
        void guardGate();
        void attack(const std::string &target);
};

#endif