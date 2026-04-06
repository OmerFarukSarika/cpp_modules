/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 03:31:47 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/24 03:40:52 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        std::string const &getType();
        void setType(std::string type);

    private:
        std::string _type;
};

#endif