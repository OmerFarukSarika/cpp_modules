/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay < osarikay@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:42:58 by osarikay          #+#    #+#             */
/*   Updated: 2025/02/09 17:09:17 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        virtual ~FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap(std::string const &name);
        FragTrap &operator=(const FragTrap &copy);
        void highFivesGuys();
};

#endif