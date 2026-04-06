/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:56:29 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/24 00:08:39 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void announce();
        void setName(std::string name);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif