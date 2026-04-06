/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 03:35:49 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/24 03:36:14 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        void attack();

    private:
        std::string _name;
        Weapon &_weapon;
};

#endif