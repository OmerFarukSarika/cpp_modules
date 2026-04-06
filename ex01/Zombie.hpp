/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarikay <osarikay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:44:24 by osarikay          #+#    #+#             */
/*   Updated: 2025/01/24 00:46:47 by osarikay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif